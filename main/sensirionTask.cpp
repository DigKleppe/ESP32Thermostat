/*
 * sensirionTask.cpp
 *
 *  Created on: Jan 5, 2022
 *      Author: dig
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "guiTask.h"
#include "guiCommonTask.h"
#include "sensirionTask.h"
#include "connect.h"
#include "udpClient.h"
#include "PID.h"
#include "settings.h"
#include "ntcTask.h"


#include "SparkFun_SCD30_Arduino_Library.h"

#define UDPTXPORT	5001

extern int scriptState;
extern SemaphoreHandle_t I2CSemaphore;  // used by lvgl, shares the same bus


#define MAXLOGVALUES			(24*60)

typedef struct {
	int32_t timeStamp;
	float temperature;
	float hum;
	int32_t co2;
	float PIDsetting;
} log_t;

static log_t tLog[ MAXLOGVALUES];
static log_t lastVal;
static int timeStamp =0;

static int logTxIdx;
static int logRxIdx;

void testLog(void) {
//	logTxIdx = 0;
	for (int p = 0; p < 20; p++) {
		tLog[logTxIdx].timeStamp = timeStamp++;
		tLog[logTxIdx].temperature = 10 + (float) p/10.0;
		tLog[logTxIdx].hum = 20 + (float) p/3.0;
		tLog[logTxIdx].co2 = 200 + p;
		tLog[logTxIdx].PIDsetting = 12.3;
		logTxIdx++;
		if (logTxIdx >= MAXLOGVALUES )
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

float getTemperature (void) {
	return lastVal.temperature;
}
extern bool connected;

float to; // test
void setPWM(int perc);


void sensirionTask(void *pvParameter) {
    time_t now = 0;
    struct tm timeinfo;
    int lastminute = -1;
	SCD30 airSensor;
	char str[25];
	char str2[25];
	uint32_t dummy;
	displayMssg_t displayMssg;
	displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
	displayMssg.str1 = str;
	displayMssg.str2 = str2;
	int sensirionTimeoutTimer = 60;

	while( displayMssgBox == NULL){ // wait for display
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
	time(&now);
	xSemaphoreTake(I2CSemaphore, portMAX_DELAY);

	while ((airSensor.begin(Wire,false, false) == false) && (sensirionTimeoutTimer-- >0))
	{
		airSensor.reset();
		Serial.println("Air sensor not detected");

		xSemaphoreGive(I2CSemaphore);
		vTaskDelay(200 / portTICK_PERIOD_MS);
		xSemaphoreTake(I2CSemaphore, portMAX_DELAY);
	}
	displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
	airSensor.setMeasurementInterval(MEASINTERVAL);
	airSensor.setAutoSelfCalibration(true);
	airSensor.setTemperatureOffset(3.0);

	to = 	airSensor.getTemperatureOffset();

	xSemaphoreGive(I2CSemaphore);
	sensirionTimeoutTimer = 60;
	//testLog();
	while (1) {
		vTaskDelay(1000 / portTICK_PERIOD_MS);

		lastVal.temperature  = NTCtemperature- userSettings.temperatureOffset;  // SDC30 not accurate enough
		displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;

		if (sensirionTimeoutTimer-- == 0) {

			Serial.println("Air sensor timeout");
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
					xQueueReceive(displayReadyMssgBox, &dummy,
							500 / portTICK_PERIOD_MS); // if accepted wait until data is displayed
			}
			xSemaphoreTake(I2CSemaphore, portMAX_DELAY);
			airSensor.reset();

			sensirionTimeoutTimer = 100;
			while ((airSensor.begin(Wire,false, false) == false) && (sensirionTimeoutTimer-- >0));
			xSemaphoreGive(I2CSemaphore);
			vTaskDelay(200 / portTICK_PERIOD_MS);
		}


		if (pdTRUE == xSemaphoreTake(I2CSemaphore, portMAX_DELAY)) {
			if (airSensor.dataAvailable()) {
				sensirionTimeoutTimer = 60;
				lastVal.co2  = airSensor.getCO2();
			//	lastVal.temperature  = airSensor.getTemperature() - userSettings.temperatureOffset;
				lastVal.hum  = airSensor.getHumidity();
				lastVal.timeStamp = timeStamp++;
				xSemaphoreGive(I2CSemaphore);
				displayMssg.displayItem = DISPLAY_ITEM_MEASLINE;
				updatePID(lastVal.temperature);
				lastVal.PIDsetting = PIDsetting;

				for (int n = 0; n < 3; n++) {
					displayMssg.line = n;
					switch (n){
					case 0:
						sprintf(str, "%2.1f",lastVal.temperature);
						break;
					case 1:
						sprintf(str, "%2.1f",lastVal.hum);
						break;
					case 2:
						sprintf(str, "%d",lastVal.co2);
						break;
					}
					xQueueReceive(displayReadyMssgBox, &dummy, 0); // empty mssgbox
					if ( xQueueSend( displayMssgBox, &displayMssg, 0 ) == pdPASS)
						xQueueReceive(displayReadyMssgBox, &dummy, 500/portTICK_PERIOD_MS); // if accepted wait until data is displayed
				}

				Serial.print("co2(ppm):");
				Serial.print(lastVal.co2, 1);
				Serial.print(" temp(C):");
				Serial.print(lastVal.temperature, 1);
				Serial.print(" humidity(%):");
				Serial.print(lastVal.hum, 1);
				Serial.println();

				sprintf( str, "1:%d",lastVal.co2);
				UDPsendMssg(UDPTXPORT, str , strlen(str));

				time(&now);
				localtime_r(&now, &timeinfo);
				if (lastminute != timeinfo.tm_min ) {
					 lastminute = timeinfo.tm_min;   // every minute
					 tLog[logTxIdx] = lastVal;
					 logTxIdx++;
					 if (logTxIdx >= MAXLOGVALUES)
						logTxIdx = 0;
				}
			}
			xSemaphoreGive(I2CSemaphore);
		}
	}
}

// called from CGI

int getRTMeasValuesScript(char *pBuffer, int count) {
int len = 0;

switch (scriptState) {
case 0:
	scriptState++;
	len += sprintf(pBuffer + len, "%d,", lastVal.timeStamp);
	len += sprintf(pBuffer + len, "%3.2f,", lastVal.temperature);
	len += sprintf(pBuffer + len, "%3.2f,", lastVal.hum);
	len += sprintf(pBuffer + len, "%d,", lastVal.co2);
	len += sprintf(pBuffer + len, "%3.1f\n",lastVal.PIDsetting);
	return len;
	break;
default:
	break;
}
return 0;
}


// these functions only work for one user!

int getNewMeasValuesScript(char *pBuffer, int count) {

int left, len = 0;
if (logRxIdx != (logTxIdx)) {  // something to send?
	do {
		len += sprintf(pBuffer + len, "%d,", tLog[logRxIdx].timeStamp);
		len += sprintf(pBuffer + len, "%3.2f,", tLog[logRxIdx].temperature);
		len += sprintf(pBuffer + len, "%3.2f,", tLog[logRxIdx].hum);
		len += sprintf(pBuffer + len, "%d,", tLog[logRxIdx].co2);
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
				len += sprintf(pBuffer + len, "%d,", tLog[logRxIdx].timeStamp);
				len += sprintf(pBuffer + len, "%3.2f,", tLog[logRxIdx].temperature);
				len += sprintf(pBuffer + len, "%3.2f,", tLog[logRxIdx].hum);
				len += sprintf(pBuffer + len, "%d,", tLog[logRxIdx].co2);
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

