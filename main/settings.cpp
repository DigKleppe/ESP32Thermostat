/*
 * settings.c
 *
 *  Created on: Nov 30, 2017
 *      Author: dig
 */

#include "settings.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "driver/gpio.h"
#include <string.h>
#include <cerrno>

#define STORAGE_NAMESPACE "storage"

extern settingsDescr_t settingsDescr[];
extern int myRssi;
bool settingsChanged;

char checkstr[MAX_STRLEN+1];

const userSettings_t userSettingsDefaults = {
	{.SSID= "Klepnet"},
	{.pwd = "xxxxx"},
	.temperatureSetpoint = 19.0,
	.temperatureOffset = 3.0,
	.PIDp = 10.0,
	.PIDi = 1.0,
	.PIDmaxi = 100,
	.controlInterval = 15,
	.heatingOn = true,
	.coolingOn = true,
	.backLigth = 40,
	{.checkstr = CHECKSTR}
};

userSettings_t userSettings;




esp_err_t saveUserSettings(void)
{
	FILE *fd = fopen("/spiffs/settings", "wb");
	if (fd == NULL) {
		printf("  Error opening file (%d) %s\n", errno, strerror(errno));
		printf("\n");
		return-1;
	}
	int len = sizeof (userSettings_t);
	int res = fwrite( &userSettings, 1, len, fd);
	if (res != len) {
		printf("  Error writing to file(%d <> %d\n", res, len);
		res = fclose(fd);
		return -1;
	}
	res = fclose(fd);
	return 0;
}

esp_err_t loadUserSettings(){
	esp_err_t res = 0;
	FILE *fd = fopen("/spiffs/settings", "rb");
	if (fd == NULL) {
		printf("  Error opening settings file (%d) %s\n", errno, strerror(errno));

	}
	else {
		int len = sizeof (userSettings_t);
		res = fread( &userSettings, 1, len, fd);
		if (res <= 0) {
			printf("  Error reading from file\n");
		}
		res = fclose(fd);
	}
	if (strcmp(userSettings.checkstr, CHECKSTR) != 0 ){
		userSettings = userSettingsDefaults;
		printf( " ** defaults loaded");
		saveUserSettings();
	}
	return res;
}


