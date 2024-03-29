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

#include "cgiScripts.h"


#define MAX_STRLEN 32
#define USERSETTINGS_CHECKSTR 	"test2"
#define CALCHECKSTR  			"test2"

typedef struct {
	char spiffsVersion[16]; // holding current version
	float temperatureSetpoint;
	float temperatureOffset;
	float CO2offset;
	float RHoffset;
	float PIDp;
	float PIDi;
	float PIDmaxi;
	float controlInterval;
	bool heatingOn;
	bool coolingOn;
	float backLight;
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


esp_err_t saveSettings( void);
esp_err_t loadSettings( void);

extern userSettings_t userSettings;





#endif /* SETTINGS_H_ */
