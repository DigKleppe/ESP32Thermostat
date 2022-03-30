/*
 * NavigArrows.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: dig
 *
 *      0xF060,0xF061,0xF053,0xF054
 *      0123456789,:.-+%
 */

#include <NavigArrows.h>



extern lv_font_t insloata100_4bppSub;

LV_FONT_DECLARE(Awsome50)
//#define FONT &dejaVuSansMono904bppSub
//#define FONT &insloata100_4bppSub

LV_FONT_DECLARE(lv_font_montserrat_44)
#define FONT	lv_font_montserrat_44 //Awsome50

static lv_style_t style;
static bool styleIsSet;


static void rightClick(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_SHORT_CLICKED)
    {
    }
}


static void leftClick(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_SHORT_CLICKED ) {

    }
}



NavigArrows::NavigArrows(lv_obj_t* parent, bool right, bool left) {

	_parent = parent;
	if (!styleIsSet) {
		styleIsSet = true;
		lv_style_init(&style);
//	lv_style_set_bg_color(&style, lv_color_black());
		lv_style_set_text_font(&style, &FONT);
		lv_color_t c = lv_color_make(255, 255, 0);
		lv_style_set_text_color(&style, c);
	}

	if (right) {
		buttonRight = lv_btn_create(_parent);
		lv_obj_set_size(buttonRight, 100, 70);
		lv_obj_align(buttonRight, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
		lv_obj_add_style(buttonRight,&style, 0);

	//	lv_obj_t* lbel = lv_label_create(buttonRight);
	//	lv_obj_set_pos( lbel, 30,-5);
//		lv_obj_center(lbel);
	//	lv_obj_add_style( lbel, &styel,0);
	//	lv_label_set_text(lbel, LV_SYMBOL_RIGHT);
	//	lv_label_set_text(lbel,"aswa");

	//	lv_obj_center(lbel);
		lv_obj_set_style_bg_img_src(buttonRight, LV_SYMBOL_RIGHT, _LV_STYLE_STATE_CMP_SAME);
	}

	if (left) {
		buttonLeft = lv_btn_create(_parent);
		lv_obj_set_size(buttonLeft, 100, 70);
		lv_obj_align(buttonLeft, LV_ALIGN_BOTTOM_LEFT,0,0);
		lv_obj_add_style(buttonLeft, &style, 0);
//	//	lv_obj_set_style_bg_img_src(buttonLeft, LV_SYMBOL_LEFT, 0);
//		lv_obj_t* lbel2 = lv_label_create(buttonLeft);
//		lv_obj_set_pos( lbel2, 10,-5);
//	//	lbel2->
//			//	lv_obj_add_style( lbel, &styel,0);
//		lv_label_set_text(lbel2, LV_SYMBOL_LEFT);
		lv_obj_set_style_bg_img_src(buttonLeft, LV_SYMBOL_LEFT, _LV_STYLE_STATE_CMP_SAME);
	}

}

NavigArrows::~NavigArrows() {
	// TODO Auto-generated destructor stub
}

