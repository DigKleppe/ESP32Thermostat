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
//extern lv_font_t  lv_font_montserrat_40;

extern lv_font_t insloata100_4bppSub;
//#define FONT &dejaVuSansMono904bppSub
#define FONT &insloata100_4bppSub

//void scr_event_cb(lv_obj_t * obj, lv_event_t e)
//{
//    if(e == LV_EVENT_GESTURE) {
//        lv_gesture_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
//        printf("Dir: %d\n", dir);
//    }
//}



SettingsScreen::SettingsScreen() {
	settingsScreen = lv_obj_create(NULL);
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
		spinBox[n] = new SpinBox( settingsScreen);
		spinBox[n]->init(&spinBoxDescr[n],5+  n*SPINBOXHEIGHT);
#ifndef LGL_SIMULATOR
		vTaskDelay(50/portTICK_PERIOD_MS);
#endif

	}
	navigArrows = new NavigArrows(settingsScreen, true, true);

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

