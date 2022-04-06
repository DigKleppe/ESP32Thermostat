/*
 * MeasScreen.h
 *
 *  Created on: Mar 2, 2021
 *      Author: dig
 */

#ifndef COMPONENTS_GUI_MAINSCREEN_H_
#define COMPONENTS_GUI_MAINSCREEN_H_

#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif
//http://www.ltg.ed.ac.uk/~richard/utf-8.cgi?input=3a9&mode=hex

//#include "Stream.h"

//#include "StatusLine.h"
#include "SpinBox.h"
#include "NavigArrows.h"
#include "ClockDisplay.h"

#define LV_SYMBOL_OHM    "\xef\xCE\xA9"  //0x3A9
#define LV_SYMBOL_MICRO  "\xef\xCE\xBC" //0x3BC

#define NR_ITEMS 3

class MainScreen { //public Stream{
public:
	MainScreen();
	virtual ~MainScreen();
	static const int MAXVALUECHARS = 8;
	void show();
	void setDisplayText(int line , const  char * text);
	void setValueAndName( int line , const char * value, const char * name);
	void setColors (lv_color_t bgcolor, lv_color_t textcolor);
	void setStatusLine (const char * text);
	static volatile bool active;

private:
	char  measValue1[MAXVALUECHARS+3]; // extra space for a symbol (3 characters)
	static void event_handler(lv_obj_t * obj, lv_event_t event);
	static void screenClicked(lv_event_t * event);
	lv_obj_t * backGround;
	lv_obj_t * btn[NR_ITEMS];
	lv_obj_t * label[NR_ITEMS];
//	StatusLine * statusLine;
	SpinBox * spinBoxTemperatuur;
	lv_obj_t * screen;
	NavigArrows * navigArrows;
	ClockDisplay * clockDisplay;
};

#endif /* COMPONENTS_GUI_MEASSCREEN_H_ */
