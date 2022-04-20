/* LVGL Example project
 *
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 *
 * https://vuetifyjs.com/en/styles/colors/#material-colors
 *
 *
 */


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

//#include "esp_netif_ip_addr.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "Arduino.h"

#include "connect.h"
#include "guiTask.h"
#include "guiCommonTask.h"
#include "clockTask.h"
#include "settings.h"
#include "PID.h"


void guiTask(void *pvParameter);

/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   APPLICATION MAIN
 **********************/

#include <Wire.h>
//#define SDA_PIN  	21
//#define SCL_PIN 	22
#define SDA_PIN  	32
#define SCL_PIN 	33
#define I2C_CLK		100000

static const char *TAG = "main";

SemaphoreHandle_t I2CSemaphore;  // used by lvgl touch and sensor, shares the same i2C bus

esp_err_t init_spiffs(void);
void sensirionTask(void *pvParameter);


esp_err_t start_file_server(const char *base_path);
void initialiseMdns(void);

//int getRTMeasValuesScript(char *pBuffer, int count) {
//
//	return 0;
//}
//
//int getLogScript(char *pBuffer, int count) {
//
//	return 0;
//}

TaskHandle_t  guiCommonTaskh;
TaskHandle_t  guiTaskh;
TaskHandle_t  SensirionTaskh;
TaskHandle_t  connectTaskh;

extern bool settingsChanged; // from settingsScreen
uint32_t stackWm[5];
extern "C" {
void app_main() {
	int minuteCntr = 0;
    int level = 0;
	char str[25];
	char str2[25];
	int cntr=1;
	int dummy = 0;

	displayMssg_t displayMssg;
	displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
	displayMssg.str1 = str;
	displayMssg.str2 = str2;


	ESP_LOGI(TAG, "start");
	ESP_ERROR_CHECK(nvs_flash_init());
	ESP_ERROR_CHECK(init_spiffs());


	loadUserSettings();

	gpio_pad_select_gpio(COOLING_PIN);
	gpio_set_direction(COOLING_PIN, GPIO_MODE_OUTPUT);
	gpio_pad_select_gpio(HEATING_PIN);
	gpio_set_direction(HEATING_PIN, GPIO_MODE_OUTPUT);

	I2CSemaphore = xSemaphoreCreateMutex();
	Wire.begin(SDA_PIN, SCL_PIN, (uint32_t) I2C_CLK);
	Serial.begin(115200);
	Serial.println("SCD30");
//	while (1) {
//		vTaskDelay(100);
//	//	Serial.println("SCD30");
//        gpio_set_level(GPIO_NUM_4, level);
//        level = !level;
//	}

	/* If you want to use a task to create the graphic, you NEED to create a Pinned task
	 * Otherwise there can be problem such as memory corruption and so on.
	 * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */

	initGui();

    xTaskCreatePinnedToCore(guiCommonTask, "guicommon", 4096*2, NULL, 0, &guiCommonTaskh, 1);
	xTaskCreatePinnedToCore(guiTask, "guiTask", 4096 , NULL, 0, &guiTaskh, 1);
	xTaskCreate(sensirionTask, "sensirionTask", 2048, NULL, 0, &SensirionTaskh);
	connect(&connectTaskh);
	xTaskCreate(clockTask, "clock", 2*1024, NULL, 0, NULL);

	while ( ! displayReady )
		vTaskDelay (10/portTICK_PERIOD_MS);

	setBacklight(40);

	while(1) {
		vTaskDelay( 1000 / portTICK_PERIOD_MS);

		if (settingsChanged) {
			minuteCntr = 60;
			settingsChanged = false;
		}
		if (minuteCntr) {
			minuteCntr--;
			if (minuteCntr == 0)
				saveUserSettings(); // save setttings after delay
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

