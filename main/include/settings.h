/*
 * settings.h
 *
 *  Created on: Nov 30, 2017
 *      Author: dig
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <stdbool.h>
#include "esp_system.h"
#include <time.h>
#include <sys/time.h>

typedef enum { FLT, STR, INT , DESCR , CALVAL} varType_t;
#define MAX_STRLEN 32
#define CHECKSTR 	 "test1"
#define CALCHECKSTR  "test2"

typedef struct {
	char SSID[MAX_STRLEN+1];
	char pwd[MAX_STRLEN+1];
	float temperatureSetpoint;
	float temperatureOffset;
	float PIDp;
	float PIDi;
	float PIDmaxi;
	float controlInterval;
	bool heatingOn;
	bool coolingOn;
	char checkstr[MAX_STRLEN+1];
}userSettings_t;

typedef struct {
	varType_t varType;
	int size;
	void * pValue;
	int minValue;
	int maxValue;
} settingsDescr_t;


extern settingsDescr_t settingsDescr[];
extern bool settingsChanged;

esp_err_t saveUserSettings( void);
esp_err_t loadUserSettings( void);

extern userSettings_t 			userSettings;


#endif /* SETTINGS_H_ */
