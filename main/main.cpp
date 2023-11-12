/*

 . /home/dig/esp/esp-idf/export.sh
 idf.py monitor -p /dev/ttyUSB2

 -s ${openocd_path}/share/openocd/scripts -f interface/ftdi/esp32_devkitj_v1.cfg -f target/esp32.cfg -c "program_esp /mnt/linuxData/projecten/git/thermostaat/SensirionSCD30/build//app.bin 0x10000 verify"

 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_ota_ops.h"
#include "esp_http_client.h"
#include "esp_image_format.h"

#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_event.h"

#include "wifiConnect.h"
#include "guiTask.h"
#include "guiCommonTask.h"
#include "clockTask.h"
#include "ntcTask.h"
#include "settings.h"
#include "PID.h"
#include "SCD30.h"
#include "updateSpiffsTask.h"
void guiTask(void *pvParameter);


#define SDA_PIN  	32
#define SCL_PIN 	33
#define I2C_CLK		100000

#define I2C_MASTER_SCL_IO           SCL_PIN      /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           SDA_PIN      /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              I2C_NUM_0    /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          I2C_CLK      /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0            /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0            /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000

static const char *TAG = "main";

//#define HEATING_PIN 	GPIO_NUM_15  //(JTAG?)

SemaphoreHandle_t I2CSemaphore;  // used by lvgl touch and sensor, shares the same i2C bus

esp_err_t init_spiffs(void);
void sensirionTask(void *pvParameter);

TaskHandle_t guiCommonTaskh;
TaskHandle_t guiTaskh;
TaskHandle_t SensirionTaskh;
TaskHandle_t connectTaskh;
TaskHandle_t ntcTaskh;

extern bool settingsChanged; // from settingsScreen
uint32_t stackWm[5];
uint32_t upTime;


__attribute__((weak)) int getLogScript(char *pBuffer, int count)
{
	return 0;
}

__attribute__((weak)) int getRTMeasValuesScript(char *pBuffer, int count)
{
	return 0;
}

__attribute__((weak)) int getInfoValuesScript(char *pBuffer, int count)
{
	return 0;
}

// ensure after reset back to factory app for OTA
static void setBootPartitionToFactory(void) {
	esp_image_metadata_t metaData;
	esp_err_t err;

	const esp_partition_t *factPart = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, "factory");
	if (factPart != NULL) {
		esp_partition_pos_t factPartPos;
		factPartPos.offset = factPart->address;
		factPartPos.size = factPart->size;

		esp_image_verify(ESP_IMAGE_VERIFY, &factPartPos, &metaData);

		if (metaData.image.magic == ESP_IMAGE_HEADER_MAGIC) {
			ESP_LOGI(TAG, "Setting bootpartition to OTA factory");

			err = esp_ota_set_boot_partition(factPart);
			if (err != ESP_OK) {
				ESP_LOGE(TAG, "esp_ota_set_boot_partition failed (%s)!", esp_err_to_name(err));
			}
		}
	}
}
/**
 * @brief i2c master initialization
 */
static esp_err_t i2c_master_init(void) {
	i2c_port_t i2c_master_port = I2C_MASTER_NUM;

	i2c_config_t conf = { .mode = I2C_MODE_MASTER, .sda_io_num = I2C_MASTER_SDA_IO, .scl_io_num = I2C_MASTER_SCL_IO, .sda_pullup_en = GPIO_PULLUP_DISABLE, // no pullups, externally switched
			.scl_pullup_en = GPIO_PULLUP_DISABLE, .master = I2C_MASTER_FREQ_HZ, .clk_flags = 0, };

	i2c_param_config(i2c_master_port, &conf);
	return i2c_driver_install(i2c_master_port, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

//socket creation failed: Too many open files in system
extern "C" {
void app_main() {
	esp_err_t err;
	int minuteCntr = 0;
	int checkWebsiteUpdateTmr = 0;
	char str[25];
	char str2[25];
	char newStorageVersion[MAX_STORAGEVERSIONSIZE] = { };
	TaskHandle_t otaTaskh;

	displayMssg_t displayMssg;
	displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
	displayMssg.str1 = str;
	displayMssg.str2 = str2;

	ESP_LOGI(TAG, "start");

//	err = nvs_flash_init();
//	ESP_ERROR_CHECK(nvs_flash_erase());

	err = nvs_flash_init();
	if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		err = nvs_flash_init();
		ESP_LOGI(TAG, "nvs flash erased");
	}
	ESP_ERROR_CHECK(err);

	err = loadSettings();

	ESP_ERROR_CHECK(init_spiffs());

	setBootPartitionToFactory();

    gpio_reset_pin(HEATING_PIN);  // needed to disable JTAG

	gpio_set_direction(COOLING_PIN, GPIO_MODE_OUTPUT);
	gpio_set_direction(HEATING_PIN, GPIO_MODE_OUTPUT);
	gpio_set_drive_capability(HEATING_PIN, GPIO_DRIVE_CAP_3);
	gpio_set_drive_capability(COOLING_PIN, GPIO_DRIVE_CAP_3);

	I2CSemaphore = xSemaphoreCreateMutex();

	i2c_master_init();
	int I2CmasterPort = I2C_MASTER_NUM;

	/* If you want to use a task to create the graphic, you NEED to create a Pinned task
	 * Otherwise there can be problem such as memory corruption and so on.
	 * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */

	initGui();

	xTaskCreatePinnedToCore(guiCommonTask, "guicommon", 4096 * 2, NULL, 0, &guiCommonTaskh, 1);
	while (!displayReady)
		vTaskDelay(10 / portTICK_PERIOD_MS);

	xTaskCreatePinnedToCore(guiTask, "guiTask", 4096, NULL, 0, &guiTaskh, 1);
	xTaskCreate(sensirionTask, "sensirionTask", 4 * 1024, &I2CmasterPort, 0, &SensirionTaskh);
	xTaskCreate(ntcTask, "ntcTask", 2 * 1024, NULL, 0, &ntcTaskh);

	wifiConnect(&connectTaskh);
	xTaskCreate(clockTask, "clock", 4 * 1024, NULL, 0, NULL);

	setBacklight(userSettings.backLight);

	while (1) {
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		upTime++;

		if (connected) {
			if (wifiSettings.updated) {
				wifiSettings.updated = false;
				saveSettings();
			}
			if (checkWebsiteUpdateTmr-- <= 0) {
				checkWebsiteUpdateTmr =  10*60;
				newStorageVersion[0] = 0;
				spiffsUpdateFinised = true;
				xTaskCreate(&updateSpiffsTask, "updateSpiffsTask", 8192, (void*) newStorageVersion, 5, &otaTaskh);
				while (!spiffsUpdateFinised)
					vTaskDelay(1000);
				if (newStorageVersion[0]) {
					strcpy(userSettings.spiffsVersion, newStorageVersion);
					saveSettings();
				}
			}
		}

		if (settingsChanged) {
			minuteCntr = 60;
			setBacklight(userSettings.backLight);
			settingsChanged = false;
		}
		if (minuteCntr) {
			minuteCntr--;
			if (minuteCntr == 0)
				saveSettings(); // save setttings after delay
		}

//		stackWm[0] = uxTaskGetStackHighWaterMark( connectTaskh );
//		stackWm[1] = uxTaskGetStackHighWaterMark( guiCommonTaskh );
//		stackWm[2] = uxTaskGetStackHighWaterMark( guiTaskh );
//		stackWm[3] = uxTaskGetStackHighWaterMark( SensirionTaskh );
////		printf ( "freeHeapSize %d\n",  xPortGetFreeHeapSize());
//		printf ( "freeHeapSize MALLOC_CAP_DMA:\n");
//		heap_caps_print_heap_info(MALLOC_CAP_DMA);

//
//		cntr++;
//		sprintf( str,"status %d",cntr);
//		displayMssg.displayItem = DISPLAY_ITEM_STATUSLINE;
//
//		if ( xQueueSend( displayMssgBox, &displayMssg, 0 )== pdPASS)
//			xQueueReceive(displayReadyMssgBox, &dummy, 500);// if accepted wait until data is displayed
//
//		displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
//
//		for (int n = 0; n < 4; n++){
//			displayMssg.line = n;
//			sprintf (str , "8888888%d", cntr);
//			if ( xQueueSend( displayMssgBox, &displayMssg, 0 )== pdPASS)
//				xQueueReceive(displayReadyMssgBox, &dummy, 500);// if accepted wait until data is displayed
//		}
	}
}
}

