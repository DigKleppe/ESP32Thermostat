/*
 * sensirionTask.cpp
 *
 *  Created on: Jan 5, 2022
 *      Author: dig
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"

#include "guiTask.h"
#include "guiCommonTask.h"
#include "sensirionTask.h"
#include "udpClient.h"
#include "PID.h"
#include "settings.h"
#include "ntcTask.h"
#include "SCD30.h"
#include "cgiScripts.h"

#include <math.h>

#define UDPTXPORT	5001
#define MAXRETRIES 	5
#define SCD30_TIMEOUT 600

//#define SIMULATE

static const char *TAG = "sensirionTask";

extern int scriptState;
extern SemaphoreHandle_t I2CSemaphore;  // used by lvgl, shares the same bus

#define MAXLOGVALUES			(24*60)

typedef struct {
	int32_t timeStamp;
	float temperature;
	float hum;
	float co2;
	float PIDsetting;
} log_t;

static log_t tLog[ MAXLOGVALUES];
static log_t lastVal;
static log_t rawlastVal;
static int timeStamp = 0;

static int logTxIdx;
static int logRxIdx;

static SCD30 airSensor;

void testLog(void) {
//	logTxIdx = 0;
	for (int p = 0; p < 20; p++) {
		tLog[logTxIdx].timeStamp = timeStamp++;
		tLog[logTxIdx].temperature = 10 + (float) p / 10.0;
		tLog[logTxIdx].hum = 20 + (float) p / 3.0;
		tLog[logTxIdx].co2 = 200 + p;
		tLog[logTxIdx].PIDsetting = 12.3;
		logTxIdx++;
		if (logTxIdx >= MAXLOGVALUES)
			logTxIdx = 0;
	}
//
//	scriptState = 0;
//	do {
//		len = getLogScript(buf, 50);
//		buf[len] = 0;
//		printf("%s\r",buf);
//	} while (len);
//
//	for (int p = 0; p < 5; p++) {
//
//		tLog[logTxIdx].timeStamp = timeStamp++;
//		for (int n = 0; n < NR_NTCS; n++) {
//
//			tLog[logTxIdx].temperature[n] = p + n;
//		}
//		tLog[logTxIdx].refTemperature = tmpTemperature; // from I2C TMP117
//		logTxIdx++;
//		if (logTxIdx >= MAXLOGVALUES )
//			logTxIdx = 0;
//	}
//	do {
//		len = getNewMeasValuesScript(buf, 50);
//		buf[len] = 0;
//		printf("%s\r",buf);
//	} while (len);
//
//	printf("\r\n *************\r\n");
}

float getTemperature(void) {
	return lastVal.temperature;
}
extern bool connected;

void setPWM(int perc);

esp_err_t initSCD30(void) {
	int retries = 0;
	retries = MAXRETRIES;
	esp_err_t err;
	do {
		err = airSensor.setMeasurementInterval(MEASINTERVAL);
	} while (err != ESP_OK && (retries-- > 0));

	if (err == ESP_OK) {
		retries = MAXRETRIES;
		do {
			err = airSensor.setAutoSelfCalibration(true);
		} while (err != ESP_OK && (retries-- > 0));
	}

	if (err == ESP_OK) {
		retries = MAXRETRIES;
		do {
			err = airSensor.setTemperatureOffset(3.0);
		} while (err != ESP_OK && (retries-- > 0));
	}
	if (err == ESP_OK)
		ESP_LOGI(TAG, "initialized");
	else
		ESP_LOGE(TAG, "Error initializing!");
	return err;
}

void sensirionTask(void *pvParameter) {
	i2c_port_t I2CmasterPort = *(i2c_port_t*) pvParameter;
	time_t now = 0;
	struct tm timeinfo;
	int lastminute = -1;
	char str[25];
	char str2[25];
	uint32_t dummy;

	displayMssg_t displayMssg;
	displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
	displayMssg.str1 = str;
	displayMssg.str2 = str2;
	int sensirionTimeoutTimer = SCD30_TIMEOUT;

	bool sensirionError = false;

//	while( displayMssgBox == NULL){ // wait for display
//		vTaskDelay(100 / portTICK_PERIOD_MS);
//	}

	time(&now);

#ifdef SIMULATE
	float x = 0;

	ESP_LOGI(TAG, "Simulating Air sensor");
	while (1) {
		vTaskDelay(1000);
		lastVal.timeStamp = timeStamp++;
		rawlastVal.co2 = 500 + 100 * sin(x);
		lastVal.co2 = rawlastVal.co2 - userSettings.CO2offset;
		rawlastVal.hum = 200 + 100 * cos(x);
		lastVal.hum = rawlastVal.hum - userSettings.RHoffset;
		lastVal.temperature = 25 + 10 * sin(x + 1);
		x += 0.01;
		if (x > 1)
			x = 0;
		sprintf(str, "1:%2.0f", lastVal.co2);
		UDPsendMssg(UDPTXPORT, str, strlen(str));
		displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
		for (int n = 0; n < 3; n++) {
			displayMssg.line = n;
			switch (n) {
			case 0:
				sprintf(str, "%2.1f", lastVal.temperature);
				break;
			case 1:
				sprintf(str, "%2.1f", lastVal.hum);
				break;
			case 2:
				sprintf(str, "%2.0f", lastVal.co2);
				break;
			}
		}
		xQueueReceive(displayReadyMssgBox, &dummy, 0); // empty mssgbox
		if ( xQueueSend( displayMssgBox, &displayMssg, 0 ) == pdPASS)
			xQueueReceive(displayReadyMssgBox, &dummy, 500 / portTICK_PERIOD_MS); // if accepted wait until data is displayed

		time(&now);
		localtime_r(&now, &timeinfo);
		if (lastminute != timeinfo.tm_min) {
			lastminute = timeinfo.tm_min;   // every minute
			tLog[logTxIdx] = lastVal;
			logTxIdx++;
			if (logTxIdx >= MAXLOGVALUES)
				logTxIdx = 0;
		}
	}
}

#else
	xSemaphoreTake(I2CSemaphore, portMAX_DELAY);

	while ((airSensor.begin(I2CmasterPort, false, false) != ESP_OK) && (sensirionTimeoutTimer-- > 0)) {
		airSensor.reset();

		ESP_LOGE(TAG, "Air sensor not detected");

		xSemaphoreGive(I2CSemaphore);
		vTaskDelay(200 / portTICK_PERIOD_MS);
		xSemaphoreTake(I2CSemaphore, portMAX_DELAY);
	}

	displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
	if (initSCD30() != ESP_OK)
		sensirionError = true;

	xSemaphoreGive(I2CSemaphore);
	sensirionTimeoutTimer = SCD30_TIMEOUT;
	//testLog();
	while (1) {
		vTaskDelay(100 / portTICK_PERIOD_MS);

		rawlastVal.temperature = NTCtemperature;
		lastVal.temperature = NTCtemperature - userSettings.temperatureOffset;  // SDC30 not accurate enough, use NTC

		displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
		if (sensirionError)
			sensirionTimeoutTimer = 0; //
		if (sensirionTimeoutTimer-- == 0) {
			ESP_LOGE(TAG, "Air sensor timeout");
			for (int n = 0; n < 3; n++) {
				displayMssg.line = n;

				switch (n) {
				case 0:
					sprintf(str, "%2.1f", lastVal.temperature);
					break;
				case 1:
				case 2:
					sprintf(str, "-----");

					break;
				}
				xQueueReceive(displayReadyMssgBox, &dummy, 0); // empty mssgbox
				if ( xQueueSend( displayMssgBox, &displayMssg, 0 ) == pdPASS)
					xQueueReceive(displayReadyMssgBox, &dummy, 500 / portTICK_PERIOD_MS); // if accepted wait until data is displayed
			}
			xSemaphoreTake(I2CSemaphore, portMAX_DELAY);
			airSensor.reset();
			if (initSCD30() != ESP_OK)
				sensirionError = true;
			else
				sensirionError = false;

			sensirionTimeoutTimer = SCD30_TIMEOUT;
			while ((airSensor.begin(I2CmasterPort, false, false) != ESP_OK) && (sensirionTimeoutTimer-- > 0))
				;

			xSemaphoreGive(I2CSemaphore);
			vTaskDelay(200 / portTICK_PERIOD_MS);
		}

		if (pdTRUE == xSemaphoreTake(I2CSemaphore, portMAX_DELAY)) {
			if (airSensor.readMeasurement() == ESP_OK) {
				sensirionTimeoutTimer = SCD30_TIMEOUT;
				rawlastVal.co2 = airSensor.getCO2();
				lastVal.co2 = rawlastVal.co2 - userSettings.CO2offset;
				if (lastVal.co2 > 300) { // first measurement invalid, reject
					//	lastVal.temperature  = airSensor.getTemperature() - userSettings.temperatureOffset; NTC used
					rawlastVal.hum = airSensor.getHumidity();
					lastVal.hum = rawlastVal.hum - userSettings.RHoffset;

					lastVal.timeStamp = timeStamp++;
					xSemaphoreGive(I2CSemaphore);
					displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
					updatePID(lastVal.temperature);
					lastVal.PIDsetting = PIDsetting;
					ESP_LOGI(TAG, "t: %f co2:%f", lastVal.temperature, lastVal.co2);

					for (int n = 0; n < 3; n++) {
						displayMssg.line = n;
						switch (n) {
						case 0:
							sprintf(str, "%2.1f", lastVal.temperature);
							break;
						case 1:
							sprintf(str, "%2.1f", lastVal.hum);
							break;
						case 2:
							sprintf(str, "%2.0f", lastVal.co2);
							break;
						}
						xQueueReceive(displayReadyMssgBox, &dummy, 0); // empty mssgbox
						if ( xQueueSend( displayMssgBox, &displayMssg, 0 ) == pdPASS)
							xQueueReceive(displayReadyMssgBox, &dummy, 500 / portTICK_PERIOD_MS); // if accepted wait until data is displayed
					}

					sprintf(str, "1:%2.0f", lastVal.co2);
					UDPsendMssg(UDPTXPORT, str, strlen(str));
					time(&now);
					localtime_r(&now, &timeinfo);
					if (lastminute != timeinfo.tm_min) {
						lastminute = timeinfo.tm_min;   // every minute
						tLog[logTxIdx] = lastVal;
						logTxIdx++;
						if (logTxIdx >= MAXLOGVALUES)
							logTxIdx = 0;
					}
				}
			}
			xSemaphoreGive(I2CSemaphore);
		}
	}

}
#endif

// CGI stuff

calValues_t calValues = { NOCAL, NOCAL, NOCAL };

const CGIdesc_t writeVarDescriptors[NR_CALDESCRIPTORS] = { { "Temperatuur", &calValues.temperature, FLT, 1 }, { "RH", &calValues.RH, FLT, 1 }, { "CO2", &calValues.CO2, FLT, 1 }, };

int getRTMeasValuesScript(char *pBuffer, int count) {
	int len = 0;

	switch (scriptState) {
	case 0:
		scriptState++;
		len += sprintf(pBuffer + len, "%ld,", lastVal.timeStamp);
		len += sprintf(pBuffer + len, "%3.2f,", lastVal.temperature);
		len += sprintf(pBuffer + len, "%3.2f,", lastVal.hum);
		len += sprintf(pBuffer + len, "%3.0f,", lastVal.co2);
		len += sprintf(pBuffer + len, "%3.1f\n", lastVal.PIDsetting);
		return len;
		break;
	default:
		break;
	}
	return 0;
}

int getInfoValuesScript(char *pBuffer, int count) {
	int len = 0;
	switch (scriptState) {
	case 0:
		scriptState++;

		len += sprintf(pBuffer + len, "%s\n", "Meting,Actueel,Offset");
		len += sprintf(pBuffer + len, "%s,%3.2f,%3.2f\n", "Temperatuur", lastVal.temperature, userSettings.temperatureOffset);
		len += sprintf(pBuffer + len, "%s,%3.1f,%3.1f\n", "RH", lastVal.hum, userSettings.RHoffset);
		len += sprintf(pBuffer + len, "%s,%3.0f,%3.0f\n", "CO2", lastVal.co2, userSettings.CO2offset);

//		len += sprintf(pBuffer + len, "%ld,", lastVal.timeStamp);
//		len += sprintf(pBuffer + len, "%3.2f,", lastVal.temperature);
//		len += sprintf(pBuffer + len, "%3.1f,", lastVal.hum);
//		len += sprintf(pBuffer + len, "%3.1f\n", lastVal.PIDsetting);
		return len;
		break;
	default:
		break;
	}
	return 0;
}

// only build javascript table

int getCalValuesScript(char *pBuffer, int count) {
	int len = 0;
	switch (scriptState) {
	case 0:
		scriptState++;
		len += sprintf(pBuffer + len, "%s\n", "Meting,Referentie,Stel in,Herstel");
		len += sprintf(pBuffer + len, "%s\n", "Temperatuur\n RH\n CO2");
		return len;
		break;
	default:
		break;
	}
	return 0;
}

int saveSettingsScript(char *pBuffer, int count) {
	saveSettings();
	return 0;
}

int cancelSettingsScript(char *pBuffer, int count) {
	loadSettings();
	return 0;
}

// these functions only work for one user!

int getNewMeasValuesScript(char *pBuffer, int count) {

	int left, len = 0;
	if (logRxIdx != (logTxIdx)) {  // something to send?
		do {
			len += sprintf(pBuffer + len, "%ld,", tLog[logRxIdx].timeStamp);
			len += sprintf(pBuffer + len, "%3.2f,", tLog[logRxIdx].temperature);
			len += sprintf(pBuffer + len, "%3.1f,", tLog[logRxIdx].hum);
			len += sprintf(pBuffer + len, "%3.0f,", tLog[logRxIdx].co2);
			len += sprintf(pBuffer + len, "%3.3f\n", tLog[logRxIdx].PIDsetting);
			logRxIdx++;
			if (logRxIdx > MAXLOGVALUES)
				logRxIdx = 0;
			left = count - len;

		} while ((logRxIdx != logTxIdx) && (left > 40));

	}
	return len;
}
// reads all avaiable data from log
// issued as first request.

int getLogScript(char *pBuffer, int count) {
	static int oldTimeStamp = 0;
	static int logsToSend = 0;
	int left, len = 0;
	int n;
	if (scriptState == 0) { // find oldest value in cyclic logbuffer
		logRxIdx = 0;
		oldTimeStamp = 0;
		for (n = 0; n < MAXLOGVALUES; n++) {
			if (tLog[logRxIdx].timeStamp < oldTimeStamp)
				break;
			else {
				oldTimeStamp = tLog[logRxIdx++].timeStamp;
			}
		}
		if (tLog[logRxIdx].timeStamp == 0) { // then log not full
			// not written yet?
			logRxIdx = 0;
			logsToSend = n;
		} else
			logsToSend = MAXLOGVALUES;
		scriptState++;
	}
	if (scriptState == 1) { // send complete buffer
		if (logsToSend) {
			do {
				len += sprintf(pBuffer + len, "%ld,", tLog[logRxIdx].timeStamp);
				len += sprintf(pBuffer + len, "%3.2f,", tLog[logRxIdx].temperature);
				len += sprintf(pBuffer + len, "%3.1f,", tLog[logRxIdx].hum);
				len += sprintf(pBuffer + len, "%3.0f,", tLog[logRxIdx].co2);
				len += sprintf(pBuffer + len, "%3.3f\n", tLog[logRxIdx].PIDsetting);
				logRxIdx++;
				if (logRxIdx >= MAXLOGVALUES)
					logRxIdx = 0;
				left = count - len;
				logsToSend--;

			} while (logsToSend && (left > 40));
		}
	}
	return len;
}

void parseCGIWriteData(char *buf, int received) {
	if (strncmp(buf, "setCal:", 7) == 0) {
		if (readActionScript(&buf[7], writeVarDescriptors, NR_CALDESCRIPTORS)) {
			if (calValues.temperature != NOCAL) { // then real temperature received
				userSettings.temperatureOffset = rawlastVal.temperature - calValues.temperature;
				calValues.temperature = NOCAL;
			}
			if (calValues.CO2 != NOCAL) { // then real temperature received
				userSettings.CO2offset = rawlastVal.co2 - calValues.CO2;
				calValues.CO2 = NOCAL;
			}
			if (calValues.RH != NOCAL) { // then real temperature received
				userSettings.RHoffset = rawlastVal.hum - calValues.RH;
				calValues.RH = NOCAL;
			}
		}
	}
}
