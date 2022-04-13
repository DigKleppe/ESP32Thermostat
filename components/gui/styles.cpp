/*
 * styles.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: dig
 */

#include "styles.h"

lv_style_t style_background;
lv_style_t styleValue;
lv_style_t styleNavArrows;
lv_style_t styleMeasName;
lv_style_t styleMeasUnit;

lv_style_t styleSpin;
lv_style_t styleSpinButtonName;
lv_style_t styleSpinButton;
lv_style_t styleClock;

lv_style_t styleInfo;

void initStyles ( void){

	//lv_color_t c;
	lv_style_init(&style_background);
	lv_style_set_bg_color(&style_background, DEFAULTBACKGROUNDCOLOR);
	lv_style_set_border_width(&style_background,0);
	lv_style_set_radius(&style_background,0);


	lv_style_init(&styleValue);
	lv_style_set_bg_color(&styleValue, MEASVALUEBGCOLOR);
	lv_style_set_text_font(&styleValue, &MEASFONT);
	lv_style_set_text_color(&styleValue, MEASVALUECOLOR);


	lv_style_init(&styleMeasName);
	lv_style_set_bg_color(&styleMeasName, MEASVALUEBGCOLOR);
	lv_style_set_text_font(&styleMeasName, &MEASNAMEFONT);
	lv_style_set_text_color(&styleMeasName, MEASNAMECOLOR);


	lv_style_init(&styleMeasUnit);
	lv_style_set_bg_color(&styleMeasUnit, MEASVALUEBGCOLOR);
	lv_style_set_text_font(&styleMeasUnit, &MEASUNITFONT);
	lv_style_set_text_color(&styleMeasUnit, MEASNAMECOLOR);


	lv_style_init(&styleNavArrows);
	lv_style_set_bg_color(&styleNavArrows, NAVARROWSBGCOLOR);
	lv_style_set_text_font(&styleNavArrows, &NAVIGARROWS_FONT);
	lv_style_set_text_color(&styleNavArrows, NAVIGARROWSCOLOR);

// spinbuttons

	lv_style_init(&styleSpin);  // value
	lv_style_set_bg_color(&styleSpin, SPINBUTTONVALUEBGCOLOR);
	lv_style_set_text_font(&styleSpin, &SPINBUTTONFONT);
	lv_style_set_text_color(&styleSpin, SPINBUTTONVALUECOLOR);
//	lv_style_set_radius(&styleSpin, 5);
//	lv_style_set_bg_opa(&styleSpin, LV_OPA_COVER);
//	lv_style_set_border_width(&styleSpin, 2);
//	lv_style_set_border_color(&styleSpin,  DEFAULTBORDERCOLOR);

	lv_style_init(&styleSpinButtonName);
	lv_style_set_bg_color(&styleSpinButtonName,SPINBUTTONAME_BGCOLOR);
	lv_style_set_text_font(&styleSpinButtonName, &SPINBUTTONNAMEFONT);
	lv_style_set_text_color(&styleSpinButtonName, SPINBUTTONNAMECOLOR);

	lv_style_init(&styleSpinButton);
	lv_style_set_bg_color(&styleSpinButton, SPINBUTTONBACKGROUNDCOLOR);
	lv_style_set_text_font(&styleSpinButton, &SPINBUTTONFONT);
	lv_style_set_text_color(&styleSpinButton,SPINBUTTONVALUECOLOR);
//	lv_style_set_radius(&styleSpinButton, 5);
//	lv_style_set_bg_opa(&styleSpinButton, LV_OPA_COVER);
////	lv_style_set_border_side(&styleSpinButton, LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_LEFT);
//	lv_style_set_border_width(&styleSpinButton, 1);
//	lv_style_set_border_color(&styleSpinButton,  DEFAULTBORDERCOLOR);

	lv_style_init(&styleClock);
	lv_style_set_text_font(&styleClock, &CLOCKFONT);
	lv_style_set_text_color(&styleClock, CLOCKCOLOR);
	lv_style_set_bg_color(&styleClock, CLOCKBGCOLOR);


	lv_style_init(&styleInfo);
	lv_style_set_text_font(&styleInfo, &INFOFONT);
	lv_style_set_text_color(&styleInfo, INFOCOLOR);
	lv_style_set_bg_color(&styleInfo, INFOBGCOLOR);



//	lv_style_set_radius(&styleClock, 5);
//	lv_style_set_bg_opa(&styleClock, LV_OPA_COVER);
//	lv_style_set_border_width(&styleClock, 1);
//	lv_style_set_border_color(&styleClock,  DEFAULTBORDERCOLOR);
//	lv_style_set_text_align(&styleClock, LV_TEXT_ALIGN_CENTER);

}

