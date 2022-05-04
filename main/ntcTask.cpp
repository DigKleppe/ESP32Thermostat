/*
 * ntcTask.cpp
 *
 *  Created on: May 1, 2022
 *      Author: dig
 */


#include <stdio.h>
#include <stdlib.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

#include "ntc.h"
#include "averager.h"


//ADC Channels

#define ADC1_EXAMPLE_CHAN0        ADC1_CHANNEL_6   // GPIO34   ADC1_GPIO34_CHANNEL //  ADC1_CHANNEL_6
//#define ADC2_EXAMPLE_CHAN0          ADC2_CHANNEL_0
static const char *TAG_CH[2][10] = {{"ADC1_CH6"}, {"ADC2_CH0"}};

//ADC Attenuation
#define ADC_EXAMPLE_ATTEN           ADC_ATTEN_DB_2_5

//ADC Calibration
#if CONFIG_IDF_TARGET_ESP32
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_VREF
#elif CONFIG_IDF_TARGET_ESP32S2
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_TP
#elif CONFIG_IDF_TARGET_ESP32C3
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_TP
#elif CONFIG_IDF_TARGET_ESP32S3
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_TP_FIT
#endif

#define VSUPP 3312.0
#define RREF  38480.0
//static int adc_raw[2][10];
static const char *TAG = "NTCTask";

static esp_adc_cal_characteristics_t adc1_chars;

Averager averager(32);
float NTCtemperature = -1;


static bool adc_calibration_init(void)
{
    esp_err_t ret;
    bool cali_enable = false;

    ret = esp_adc_cal_check_efuse(ADC_EXAMPLE_CALI_SCHEME);
    if (ret == ESP_ERR_NOT_SUPPORTED) {
        ESP_LOGW(TAG, "Calibration scheme not supported, skip software calibration");
    } else if (ret == ESP_ERR_INVALID_VERSION) {
        ESP_LOGW(TAG, "eFuse not burnt, skip software calibration");
    } else if (ret == ESP_OK) {
        cali_enable = true;
        esp_adc_cal_characterize(ADC_UNIT_1, ADC_EXAMPLE_ATTEN, ADC_WIDTH_BIT_12, 0, &adc1_chars);
    } else {
        ESP_LOGE(TAG, "Invalid arg");
    }
    return cali_enable;
}


void ntcTask(void *pvParameter) {

	uint32_t voltage = 0;
	bool cali_enable = adc_calibration_init();

	//ADC1 config
	ESP_ERROR_CHECK (adc1_config_width(ADC_WIDTH_BIT_12));
	ESP_ERROR_CHECK	(adc1_config_channel_atten(ADC1_EXAMPLE_CHAN0, ADC_EXAMPLE_ATTEN));

	while(	1) {
	//	adc_raw[0][0] = adc1_get_raw(ADC1_EXAMPLE_CHAN0);
		averager.write (adc1_get_raw(ADC1_EXAMPLE_CHAN0));

		// ESP_LOGI(TAG_CH[0][0], "raw  data: %d", adc_raw[0][0]);
		if (cali_enable) {
		//	voltage = esp_adc_cal_raw_to_voltage(adc_raw[0][0], &adc1_chars);
			voltage = esp_adc_cal_raw_to_voltage((int) averager.average(), &adc1_chars);

			// ESP_LOGI(TAG_CH[0][0], "cali data: %d mV", voltage);
			float R = ((float) voltage/(VSUPP-voltage)) * RREF;
			NTCtemperature= calcTemp(R);
		//	ESP_LOGI(TAG_CH[0][0], "V: %d mV  R: %4.1f E temperatuur: %2.2f",voltage, R,NTCtemperature);
		}
		vTaskDelay(pdMS_TO_TICKS(1000));
	}

}


