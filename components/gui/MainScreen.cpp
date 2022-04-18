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

#define PADDING 10
#define ITEMHEIGHT	95
#define ITEMWIDTH	300



static mainScreenVars_t vars;

const char * cbText[NR_CHECKBOXES] = {"Verwarming", "Koeling" };
const bool * cbVar[NR_CHECKBOXES] = {  &vars.heatingOn ,&vars.coolingOn };


SpinBoxDescr_t spinBoxDescrTemperatuur = {
	.name = "Gewenste temperatuur:" ,
	.format = "%2.1f",
	.maxVal = 25.0,
	.minVal = 10.0,
	.step = 0.1,
	.var = &vars.tempSetPoint,
};


//void MainScreen::event_handler(lv_event_t * e)
//static void event_handler(lv_event_t * e)
void MainScreen::event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    bool *p = ( bool *) obj->user_data;
    if(code == LV_EVENT_VALUE_CHANGED) {
        const char * txt = lv_checkbox_get_text(obj);
       	*p = (lv_obj_get_state(obj) & LV_STATE_CHECKED) ;
        const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Checked" : "Unchecked";
        LV_LOG_USER("%s: %s", txt, state);
    }
}

//void MainScreen::setTemperatureDisplayValue( float value) {
//	measDisplay->setValue ( value );
//}
//
//void MainScreen::setTemperatureDisplayText( char *text) {
//	measDisplay->setText (text);
//}

MainScreen::MainScreen() {
	screen = lv_obj_create(NULL);


	backGround =  makeBackGround(screen);
	clockDisplay = new ClockDisplay(backGround);
	statusIndicator = new StatusIndicator ( backGround);
//	measDisplay = new MeasDisplay(backGround, 40,"Temperatuur", "\xC2\xB0" "C", "%2.1f");

	spinBoxTemperatuur = new SpinBox(backGround, 1, &spinBoxDescrTemperatuur );


	for (int n = 0; n < NR_CHECKBOXES; n++) {
		cb[n] = lv_checkbox_create(screen);
		lv_checkbox_set_text(cb[n], cbText[n]);
		lv_obj_add_event_cb(cb[n], event_handler, LV_EVENT_ALL, NULL);
		lv_obj_add_style(cb[n], &styleSpinButtonName, 0);
		lv_obj_set_user_data(cb[n], (void*) cbVar[n]);
		lv_obj_set_pos(cb[n], 30, n * (55 + PADDING) + CLOCKDISPLAYHEIGHT + 250);
	}
	navigArrows = new NavigArrows(backGround, true, true);
}

void MainScreen::setValues(mainScreenVars_t *p){
	vars = *p;
//	measDisplay->setValue(p->temperature);
	spinBoxTemperatuur->upDate();
	if ( vars.heatingOn)
		lv_obj_add_state(cb[CBHEATING], LV_STATE_CHECKED);
	else
		lv_obj_clear_state(cb[CBHEATING], LV_STATE_CHECKED);

	if ( vars.coolingOn)
		lv_obj_add_state(cb[CBCOOLING], LV_STATE_CHECKED);
	else
		lv_obj_clear_state(cb[CBCOOLING], LV_STATE_CHECKED);
}

void MainScreen::getValues(mainScreenVars_t *p){
	*p = vars;
}


void MainScreen::show() {
	lv_scr_load(screen);

}


MainScreen::~MainScreen() {
	// TODO Auto-generated destructor stub
}


