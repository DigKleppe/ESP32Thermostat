/*
 * connect.h
 *
 *  Created on: Jan 23, 2022
 *      Author: dig
 */

#ifndef MAIN_CONNECT_H_
#define MAIN_CONNECT_H_

typedef struct {
	char SSID[33];
	char pwd[65];
	bool updated;
}wifiSettings_t;

extern wifiSettings_t wifiSettings;
extern char ipstr[];

void connect (TaskHandle_t *);

#endif /* MAIN_CONNECT_H_ */
