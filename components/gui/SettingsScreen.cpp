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




SettingsScreen::SettingsScreen( const SpinBoxDescr_t  * descr) {

	settingsScreen = lv_obj_create(NULL);
	backGround =  makeBackGround(settingsScreen);

	int n = -1;
	memset (spinBox,0 , sizeof (spinBox));
	do {
		n++;
		if ( descr -> name != NULL)
			spinBox[n] = new SpinBox ( backGround, n, descr);
		descr++;
	}  while((n < (NR_SPINBOXES-1)) && (descr->name != NULL));


#ifndef LGL_SIMULATOR
		vTaskDelay(50/portTICK_PERIOD_MS);
#endif
	upDate();

	navigArrows = new NavigArrows(backGround, true, true);

}

void SettingsScreen::upDate (void) {
	int n = 0;
	do {
		if (spinBox[n] != NULL)
			spinBox[n]->upDate();
		else
			n = NR_SPINBOXES;
		n++;
	}  while(n < NR_SPINBOXES);
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

