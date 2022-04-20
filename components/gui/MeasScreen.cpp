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
#include "fonts.h"

#include <stdio.h>
#include "styles.h"
#include "backGround.h"



#ifdef LGL_SIMULATOR
#include "lv_drv_conf.h"
#define LV_HOR_RES_MAX 	SDL_HOR_RES
#define LV_VER_RES_MAX SDL_VER_RES
#else
	#include "../lvgl_esp32_drivers/lvgl_helpers.h"
#endif

// fonts Ohm, micro  0x3A9,0x3BC 01234567890 -.,mMnkVAHz

#define PADDING 8
#define ITEMHEIGHT	95
#define ITEMWIDTH	200
#define FIRSTY 		CLOCKDISPLAYHEIGHT

//const char units[4][7] { "\xC2" "\xB0" "C", "%RH",  "ppm","" };
static const char * units[] = { "\xC2\xB0" "C", "%" ,"ppm"};
static const char * formats[] = { "%2.1f","%2.1f", "%d"};
static const char * name[] = { "Temperatuur:","Luchtvochtigheid:", "CO2:"};

MeasScreen::MeasScreen( ) {

	screen = lv_obj_create(NULL);
	backGround =  makeBackGround(screen);
	clockDisplay = new ClockDisplay(backGround);
	statusIndicator = new StatusIndicator(backGround);

	for (int n = 0; n < NR_ITEMS; n++) {
		measDisplay[n] = new MeasDisplay (backGround,FIRSTY + n * (ITEMHEIGHT + PADDING) + PADDING,  name[n], units[n], formats[n]);
	}
	navigArrows = new NavigArrows(backGround, true, true);
}

void MeasScreen::setDisplayText(int line, char *text) {
	measDisplay[line]->setText ( text);
	if ( line == 1)
		setStatsuIndicator(thermostatStatus);
//	if (strlen ( text) > MAXVALUECHARS)
//		text[MAXVALUECHARS+1] = 0; // terminate
//	lv_label_set_text(valueLabel[line], text);
}

void MeasScreen::setDisplayValue(int line , float value) {
	measDisplay[line]->setValue ( value );

}


void MeasScreen::setStatsuIndicator (thermostatStatus_t status) {
	switch (status) {
	case THERMOSTATOFF:
		statusIndicator->setSymbol(NULL);
		break;
	case HEATING_ON:
		statusIndicator->setSymbol(HEATERON_SIMBOL);
		break;
	case COOLING_ON:
		statusIndicator->setSymbol(COOLINGON_SYMBOL);
		break;
	}
}

void MeasScreen::setDisplayValue(int line , int value) {
	measDisplay[line]->setValue ( value );
//	char str[20];
//	sprintf( str, "%d", value );
//	setDisplayText(line, str);
}

void MeasScreen::setValueAndName(int line, const char *value, const char *name) {
	setDisplayText( line,(char *)  value);
	//lv_label_set_text(label[line], name);
}

void MeasScreen::show() {
	lv_scr_load(screen);
}



MeasScreen::~MeasScreen() {
	// TODO Auto-generated destructor stub
}

void makeMeasScreen(void) {

}

