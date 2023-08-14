/*
 * connect.h
 *
 *  Created on: Jan 23, 2022
 *      Author: dig
 */

#ifndef WIFI_CONNECT_H_
#define WIFI_CONNECT_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

typedef struct {
	char SSID[33];
	char pwd[64];
	char upgradeURL[64];
	char upgradeFileName[32];
	bool updated;
}wifiSettings_t;

extern wifiSettings_t wifiSettings;
extern char ipstr[];
extern volatile bool connected;

void wifiConnect (TaskHandle_t *);

#endif /* WIFI_CONNECT_H_ */
