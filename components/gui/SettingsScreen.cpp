/*
 * SettingsScreen.cpp
 *
 *  Created on: Mar 20, 2022
 *      Author: dig
 */

#include <SettingsScreen.h>

/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>
#include "SettingsScreen.h"
#include <stdio.h>
#include "guiCommonTask.h"
#include "settings.h"


userSettings_t 	userSettings;



SettingsScreen::SettingsScreen() {

	settingsScreen = lv_obj_create(NULL);
	backGround =  makeBackGround(settingsScreen);

	SpinBoxDescr_t spinBoxDescr[4] = {
		{{.name = "  temperatuur offset:" },
		{.format = "%2.1f"},
		.maxVal = +5.0,
		.minVal = -54.0,
		.step = 0.1,
		.var = &userSettings.temperatureOffset,
		},
		{{.name = "  temperatuur offset:" },
			{.format = "%2.1f"},
			.maxVal = +5.0,
			.minVal = -54.0,
			.step = 0.1,
			.var = &userSettings.temperatureOffset,
		},
		{{.name = "  temperatuur offset:" },
			{.format = "%2.1f"},
			.maxVal = +5.0,
			.minVal = -54.0,
			.step = 0.1,
			.var = &userSettings.temperatureOffset,
		},
		{{.name = "  temperatuur offset:" },
			{.format = "%2.1f"},
			.maxVal = +5.0,
			.minVal = -54.0,
			.step = 0.1,
			.var = &userSettings.temperatureOffset,

		}
	};

	for ( int n = 0; n < NR_SPINBOXES; n++){
		spinBox[n] = new SpinBox( backGround);
		spinBox[n]->init(&spinBoxDescr[n],  n*SPINBOXHEIGHT);
#ifndef LGL_SIMULATOR
		vTaskDelay(50/portTICK_PERIOD_MS);
#endif

	}
	navigArrows = new NavigArrows(backGround, true, true);

}




void SettingsScreen::show() {
//	lv_scr_load(lv_scr_act());
	lv_scr_load(settingsScreen);

}

SettingsScreen::~SettingsScreen() {
	// TODO Auto-generated destructor stub
}

void makeSettingsScreen(void) {

}

