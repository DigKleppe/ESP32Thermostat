/*
 * guiTask.c
 *
 *  Created on: Mar 2, 2021
 *      Author: dig
 *
 *      handles screens
 */

#include "MeasScreen.h"
//#include "MenuSettings.h"
//#include "MessageScreen.h"
#include "SettingsScreen.h"
#include "MainScreen.h"

#include "guiTask.h"
#include "guiCommonTask.h"
#include "SettingsScreen.h"

//extern "C" {      if ( timer++ == 200) {

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "styles.h"

#include "settings.h"

//extern MenuSetttingsDesrc_t DMMSettingsDescrTable[];
extern "C" void disp_wait_for_pending_transactions(void);

userState_t userState = USER_STATE_RUN;

QueueHandle_t displayMssgBox;
QueueHandle_t displayReadyMssgBox;

SettingsScreen *settingsScreen1;
SettingsScreen *settingsScreen2;
MainScreen *mainScreen;
MeasScreen *measScreen;

int screenIdx;

#define NRSCREENS 4


const SpinBoxDescr_t settingsScreenDescr1[] = {
	{
	.name = "temperatuur offset:" ,
	.format = "%2.1f",
	.maxVal = +5.0,
	.minVal = -5.0,
	.step = 0.1,
	.var = &userSettings.temperatureOffset,
	},
	{.name = "P-factor:" ,
		.format = "%1.2f",
		.maxVal = 100,
		.minVal = 0,
		.step = 0.1,
		.var = &userSettings.PIDp,
	},
	{.name = "I-factor:" ,
		.format = "%2.1f",
		.maxVal = 100,
		.minVal = 0,
		.step = 0.1,
		.var = &userSettings.PIDi,
	},
	{.name = "Max I:" ,
		.format = "%2.1f",
		.maxVal = 100,
		.minVal = 0,
		.step = 0.1,
		.var = &userSettings.PIDmaxi,
	},
	{.name = NULL ,
		.format = NULL,
		.maxVal = 100,
		.minVal = 0,
		.step = 0.1,
		.var = NULL,
	}
};


const SpinBoxDescr_t settingsScreenDescr2[] = {
	{
	.name = "Control interval:" ,
	.format = "%2.0f",
	.maxVal = 100,
	.minVal = 1,
	.step = 1,
	.var = &userSettings.controlInterval,
	},
	{
	.name = NULL,
	.format = NULL,
	.maxVal = 100,
	.minVal = 0,
	.step = 0.1,
	.var = NULL,
	}
};




void showScreen(int idx) {
	switch (idx) {
	case 0:
		measScreen->show();
		break;
	case 1:
		mainScreen->show();
		break;
	case 2:
		settingsScreen1->show();
		break;
	case 3:
		settingsScreen2->show();
		break;

	default:
		break;

	}
}

void nextScreenClick(lv_event_t *e) {  // from navigArrows
	if (screenIdx < (NRSCREENS - 1))
		screenIdx++;
	else
		screenIdx = 0;
	showScreen(screenIdx);
}

void prevScreenClick(lv_event_t *e) {  // from navigArrows
	if (screenIdx > 0)
		screenIdx--;
	else
		screenIdx = NRSCREENS-1;
	showScreen(screenIdx);
}

void guiTask(void *pvParameter) {
	displayMssg_t recDdisplayMssg;
	int dummy;
	int step = 0;

	displayMssgBox = xQueueCreate(5, sizeof(displayMssg_t));
	displayReadyMssgBox = xQueueCreate(1, sizeof(uint32_t));

	initStyles();

	while (!displayReady)
		vTaskDelay(100 / portTICK_RATE_MS);

	settingsScreen1 = new SettingsScreen(&settingsScreenDescr1[0]);
	settingsScreen2 = new SettingsScreen(&settingsScreenDescr2[0]);
//	settingsScreen2 = new SettingsScreen(&settingsScreenDescr1[0]);
	mainScreen = new MainScreen();
	measScreen = new MeasScreen();

	showScreen(0);

//	vTaskDelay( 100/portTICK_PERIOD_MS);
//	settingsScreen.show();
//
//	while (1) {
//		vTaskDelay(1000 / portTICK_PERIOD_MS);
//
//		switch (step) {
//		case 0:
//			mainScreen.show();
//			break;
//
//		case 1:
//			settingsScreen.show();
//			break;
//
//		case 2:
//			measScreen.show();
//			step = -1;
//			break;
//
//		default:
//			break;
//		};
//		step++;
//	}
//
	while (1) {
		if (xQueueReceive(displayMssgBox, &recDdisplayMssg, 0) == pdTRUE) {
			if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
				switch (recDdisplayMssg.displayItem) {
				case DISPLAY_ITEM_STATUSLINE:
//					measScreen.setStatusLine(
//							(const char*) recDdisplayMssg.str1);
					break;

				case DISPLAY_ITEM_MEASLINE:
					measScreen->setDisplayText(recDdisplayMssg.line,(char *) recDdisplayMssg.str1);

//					if ( recDdisplayMssg.line == 0)
//						mainScreen->setTemperatureDisplayText( (char *) recDdisplayMssg.str1 );
					break;
				case DISPLAY_ITEM_STOP:
				case DISPLAY_ITEM_COLOR:
					break;

				case DISPLAY_ITEM_MESSAGE:
					//	messageScreen.show ((const char *) recDdisplayMssg.str1 , LV_COLOR_BLACK, recDdisplayMssg.showTime);
					break;
				}
				disp_wait_for_pending_transactions();
				xSemaphoreGive(xGuiSemaphore);
			}
			xQueueSend(displayReadyMssgBox, &dummy, 0);

		}
	}
}


// /home/dig/.espressif/tools/openocd-esp32/v0.10.0-esp32-20200420/openocd-esp32/bin/openocd -f interface/ftdi/c232hm.cfg -f board/esp-wroom-32.cfg -c "program_esp /home/dig/projecten/littleVGL/dmmGui/build/dmm. 0x10000 verify"
