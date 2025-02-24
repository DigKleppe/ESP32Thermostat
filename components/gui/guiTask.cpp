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
#include "InfoScreen.h"
#include "guiTask.h"
#include "guiCommonTask.h"
#include "SettingsScreen.h"

//extern "C" {      if ( timer++ == 200) {

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "styles.h"

#include "wifiConnect.h"
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
InfoScreen *infoScreen;

int screenIdx;
extern float PIDsetting;
extern char myIP[];
extern uint32_t upTime;


#define NRSCREENS 5

const SpinBoxDescr_t settingsScreenDescr1[] = {
	{	.name = "P-factor:" ,
		.format = "%1.2f",
		.maxVal = 100,
		.minVal = 0,
		.step = 1,
		.var = &userSettings.PIDp,
	},
	{	.name = "I-factor:" ,
		.format = "%2.1f",
		.maxVal = 100,
		.minVal = 0,
		.step = 0.1,
		.var = &userSettings.PIDi,
	},
	{	.name = "Max I:" ,
		.format = "%2.1f",
		.maxVal = 100,
		.minVal = 0,
		.step = 5,
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
		.name = "temperatuur offset:" ,
		.format = "%2.1f",
		.maxVal = +5.0,
		.minVal = -5.0,
		.step = 0.1,
		.var = &userSettings.temperatureOffset,
	},
	{
		.name = "CO2 offset:" ,
		.format = "%2.0f",
		.maxVal = +500.0,
		.minVal = -5000,
		.step = 1,
		.var = &userSettings.CO2offset,
	},
	{
		.name = "Control interval:" ,
		.format = "%2.0f",
		.maxVal = 100,
		.minVal = 1,
		.step = 1,
		.var = &userSettings.controlInterval,
	},
	{
		.name = "Schermverlichting:" ,
		.format = "%2.0f",
		.maxVal = 80,
		.minVal = 5,
		.step = 5,
		.var = &userSettings.backLight,
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


const infoDescr_t infoDesc[] = {
	{"Netwerk:" ,"%s", wifiSettings.SSID },
	{"IPadres:","%s",myIP },
	{"PID:","%2.2f", &PIDsetting },
	{"Optijd:","%d", &upTime },
	{NULL,NULL ,NULL}
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
	case 4:
		infoScreen->show();
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
		vTaskDelay(100 / portTICK_PERIOD_MS);

	settingsScreen1 = new SettingsScreen(settingsScreenDescr1);
	settingsScreen2 = new SettingsScreen(settingsScreenDescr2);
	mainScreen = new MainScreen();
	measScreen = new MeasScreen();
	infoScreen = new InfoScreen(infoDesc);
	vTaskDelay(50/portTICK_PERIOD_MS);
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
		//	xQueueSend(displayReadyMssgBox, &dummy, 0);
		}
		xQueueSend(displayReadyMssgBox, &dummy, 0);
	}
}


// /home/dig/.espressif/tools/openocd-esp32/v0.10.0-esp32-20200420/openocd-esp32/bin/openocd -f interface/ftdi/c232hm.cfg -f board/esp-wroom-32.cfg -c "program_esp /home/dig/projecten/littleVGL/dmmGui/build/dmm. 0x10000 verify"
