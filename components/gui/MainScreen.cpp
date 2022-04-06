/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>
#include "MainScreen.h"
#include <stdio.h>
#include "guiCommonTask.h"
#include "backGround.h"


#include "fonts.h"



// fonts Ohm, micro  0x3A9,0x3BC 01234567890 -.,mMnkVAHz


//#define FONT &dejaVuSansMono904bppSub

#define PADDING 10
#define ITEMHEIGHT	95
#define ITEMWIDTH	300

//
//static void album_gesture_event_cb(lv_event_t * e)
//{
//    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
//    printf("Dir: %d\n", dir);
//}

float tempSetPoint = 20.0;  //
float offset = -0;
int tempDegr = 20;
int tempTens = 0;



//void scr_event_cb(lv_obj_t * obj, lv_event_t e)
//{
//    if(e == LV_EVENT_GESTURE) {
//        lv_gesture_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
//        printf("Dir: %d\n", dir);
//    }
//}

MainScreen::MainScreen() {

	screen = lv_obj_create(NULL);
	SpinBoxDescr_t spinBoxDescrTemperatuur = {
		{.name = "  gewenste temperatuur:" },
		{.format = "%2.1f"},
		.maxVal = 25.0,
		.minVal = 10.0,
		.step = 0.1,
		.var = &tempSetPoint,
	};

	backGround =  makeBackGround(screen);
	clockDisplay = new ClockDisplay(backGround);

	spinBoxTemperatuur = new SpinBox(backGround );

	spinBoxTemperatuur-> init(&spinBoxDescrTemperatuur, 200);


	navigArrows = new NavigArrows(backGround, true, true);


//	lv_ex_spinbox_1();




//
//	for (int n = 0; n < NR_ITEMS; n++) {
//		btn[n] = lv_btn_create(backGround);
//		lv_obj_set_pos(btn[n], PADDING, n * (ITEMHEIGHT + PADDING) + PADDING);
//		lv_obj_set_size(btn[n], ITEMWIDTH-2*PADDING, ITEMHEIGHT-PADDING);
//		lv_obj_add_style(btn[n], &style_green, 0);
//		label[n] = lv_label_create(btn[n]);
//		lv_label_set_text(label[n], "---");
//		lv_obj_center(label[n]);
//		lv_obj_add_event_cb(btn[n], screenClicked,(lv_event_code_t)LV_EVENT_GESTURE, NULL);
//	//	lv_obj_add_event_cb(btn[n], album_gesture_event_cb,(lv_event_code_t)LV_EVENT_GESTURE, NULL);
//
//
//	}
	//lv_obj_add_event_cb(btn[0], screenClicked, LV_EVENT_CLICKED, NULL);   /*Assign an event callback*/
//	statusLine = new StatusLine(screen);
}



void MainScreen::setDisplayText(int line, const char *text) {
	int len = strlen(text);

	if (len >= MAXVALUECHARS)
		memcpy(measValue1, text, MAXVALUECHARS);
	else {
		memcpy(measValue1, text, len);
		for (int n = len; n < MAXVALUECHARS; n++)
			measValue1[MAXVALUECHARS] = 0;
	}
	lv_label_set_text(label[line], measValue1);
}

/**
 * @brief
 * @param value
 * @param name
 */
void MainScreen::setValueAndName(int line, const char *value, const char *name) {
	bool hasSymbol = false;
	int valLen = strlen(value);
	int nameLen = 0;

	if (name != NULL) {
		do {
			if ((uint8_t) name[nameLen] == 0xef)
				hasSymbol = true;
			nameLen++;
		} while ((uint8_t) name[nameLen] != 0);
	}

	if (nameLen == 0)
		lv_label_set_text(label[line], value);
	else {
		if (hasSymbol) {  // assumend only 1 symbol
			memcpy(&measValue1[MAXVALUECHARS + 2 - nameLen], name, nameLen); // set value at last positions of display
			nameLen -= 2;  // subtract 2 extra characters for symbol
		} else
			memcpy(&measValue1[MAXVALUECHARS - nameLen], name, nameLen); // set value at last positions of display

		int pos = MAXVALUECHARS - nameLen - valLen;
		if (pos < 0) {
			valLen += pos; // does not fit
			pos = 0;
		}
		for (int n = 0; n < pos; n++) {
			measValue1[n] = ' '; // fill spaces at first part of line
		}
		if ((valLen + pos) <= MAXVALUECHARS) {
			memcpy(&measValue1[pos], value, valLen);
			if (hasSymbol)
				measValue1[MAXVALUECHARS + 2] = 0;
			else
				measValue1[MAXVALUECHARS] = 0;
			lv_label_set_text(label[line], measValue1);
		} else
			lv_label_set_text(label[line], "....");
	}
}


void MainScreen::show() {
	lv_scr_load(screen);
//	lv_indev_set_group(kb_indev ,g);
//	active = true;
}

void MainScreen::setColors(lv_color_t bgColor, lv_color_t textColor) {
//	lv_style_set_bg_color(&measStyle1, LV_STATE_DEFAULT, bgColor);
//	lv_style_set_text_color(&measStyle1, LV_STATE_DEFAULT, textColor);
}

MainScreen::~MainScreen() {
	// TODO Auto-generated destructor stub
}

void makeMainScreen(void) {

}

