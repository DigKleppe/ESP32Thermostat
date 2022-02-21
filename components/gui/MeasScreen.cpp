/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>
#include "MeasScreen.h"
//#include "guiCommonTask.h"

// fonts Ohm, micro  0x3A9,0x3BC 01234567890 -.,mMnkVAHz

//LV_FONT_DECLARE(insolata60);
//LV_FONT_DECLARE(insolata70);
//LV_FONT_DECLARE(insolata75);
//#define FONT &insolata75

extern lv_font_t insolata75;
extern lv_font_t dejaVuSansMono100;
extern lv_font_t dejaVuSansMono1004bppSub;
extern lv_font_t dejaVuSansMono50;
extern lv_font_t dejaVuSansMono904bpp;
extern lv_font_t dejaVuSansMono904bppSub;

extern lv_font_t insloata100_4bppSub;
//#define FONT &dejaVuSansMono904bppSub
#define FONT &insloata100_4bppSub

#define PADDING 10
#define ITEMHEIGHT	95
#define ITEMWIDTH	300

volatile bool MeasScreen::active;

MeasScreen::MeasScreen() {
	static lv_style_t style_red;
	static lv_style_t style_green;
	static lv_style_t style_blue;
	static lv_style_t style_white;

//	vTaskDelay((500 / portTICK_PERIOD_MS));

	lv_style_init(&style_white);
	lv_style_set_bg_color(&style_white, lv_color_black());
	lv_style_set_text_font(&style_white, FONT);
//	lv_style_set_text_color(&style_red, lv_palette_lighten(LV_PALETTE_YELLOW, 5));
	lv_style_set_text_color(&style_white, lv_color_white());

	lv_style_init(&style_red);
	lv_style_set_bg_color(&style_red, lv_color_black());
	lv_style_set_text_font(&style_red, FONT);
	lv_color_t c = lv_color_make(255, 0, 0);
	lv_style_set_text_color(&style_red, c);

	lv_style_init(&style_green);
	lv_style_set_bg_color(&style_green, lv_color_black());
	lv_style_set_text_font(&style_green, FONT);
	c = lv_color_make(0, 255, 0);
	lv_style_set_text_color(&style_green, c);

	lv_style_init(&style_blue);
	lv_style_set_bg_color(&style_blue, lv_color_black());
	lv_style_set_text_font(&style_blue, FONT);
	c = lv_color_make(0, 0, 255);
	lv_style_set_text_color(&style_blue, c);

	for (int n = 0; n < NR_ITEMS; n++) {
		btn[n] = lv_btn_create(lv_scr_act());
		lv_obj_set_pos(btn[n], PADDING, n * (ITEMHEIGHT + PADDING) + PADDING);
		lv_obj_set_size(btn[n], ITEMWIDTH, ITEMHEIGHT);
		lv_obj_add_style(btn[n], &style_green, 0);
		label[n] = lv_label_create(btn[n]);
		lv_label_set_text(label[n], "---");
		lv_obj_center(label[n]);
	}

	statusLine = new StatusLine(lv_scr_act());
}

void MeasScreen::event_handler(lv_obj_t *obj, lv_event_t event) {
//	uint32_t key;
//	if ( event == LV_EVENT_KEY ){
//		key = lv_indev_get_key(kb_indev);
//		if ( key == LV_KEY_ENTER)
//			active = false;
//		else
//			xQueueSend(keyEventQueue, &key, 0);  // send key to dmm task
//	}
}

void MeasScreen::setDisplayText(int line, const char *text) {
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
void MeasScreen::setValueAndName(int line, const char *value, const char *name) {
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

void MeasScreen::setStatusLine(const char *text) {
	statusLine->setText(text);
}

void MeasScreen::show() {
	lv_scr_load(lv_scr_act());
//	lv_indev_set_group(kb_indev ,g);
	active = true;
}

void MeasScreen::setColors(lv_color_t bgColor, lv_color_t textColor) {
//	lv_style_set_bg_color(&measStyle1, LV_STATE_DEFAULT, bgColor);
//	lv_style_set_text_color(&measStyle1, LV_STATE_DEFAULT, textColor);
}

MeasScreen::~MeasScreen() {
	// TODO Auto-generated destructor stub
}

void makeMeasScreen(void) {

}

