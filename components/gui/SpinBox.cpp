/*
 * spinBox.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: dig
 */

#include "SpinBox.h"
#include <stdio.h>

extern lv_font_t insloata100_4bppSub;
//#define FONT &dejaVuSansMono904bppSub
//#define FONT &insloata100_4bppSub

LV_FONT_DECLARE(lv_font_montserrat_44)
#define SPINBUTTONFONT	lv_font_montserrat_44
#define FONT SPINBUTTONFONT

LV_FONT_DECLARE(lv_font_montserrat_18)
#define SPINBUTTONNAMEFONT	lv_font_montserrat_18

static lv_style_t styleSpin;
static lv_style_t styleSpinButtonName;
static lv_style_t styleSpinButton;
static bool styleIsSet;



static void lv_spinbox_increment_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_SHORT_CLICKED || code  == LV_EVENT_LONG_PRESSED_REPEAT) {
      	SpinBox* ps =(SpinBox*)  e->user_data;
    	SpinBoxDescr_t *p = &ps->myDesc;
    	*p->var += p->step;
    	if ( *p->var > p->maxVal)
    		*p->var= p->maxVal;
    	char str[MAXCHARS+1];
    	sprintf( str, p->format, *p->var);
    	lv_label_set_text(p->label,str);
    }
}


static void lv_spinbox_decrement_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT) {
      	SpinBox* ps =(SpinBox*)  e->user_data;
    	SpinBoxDescr_t *p = &ps->myDesc;
    	*p->var -= p->step;
    	if ( *p->var < p->minVal)
    	   	*p->var= p->minVal;
    	char str[MAXCHARS+1];
    	sprintf( str, p->format, *p->var);
    	lv_label_set_text(p->label,str);

    }
}


SpinBox::SpinBox(lv_obj_t * parent){
	_parent = parent;
}

void SpinBox::init ( SpinBoxDescr_t * desc, int y)
{
	lv_coord_t h;
	lv_obj_t * namelabel;
	myDesc = *desc;

	if (!styleIsSet) {
		styleIsSet = true;
		lv_style_init(&styleSpin);
		lv_style_set_bg_color(&styleSpin, lv_color_black());
		lv_style_set_text_font(&styleSpin, &FONT);

		lv_color_t c = lv_color_make(255, 255, 0);
		lv_style_set_text_color(&styleSpin, c);
		lv_style_set_radius(&styleSpin, 5);
		lv_style_set_bg_opa(&styleSpin, LV_OPA_COVER);
		lv_style_set_border_width(&styleSpin, 2);
		lv_style_set_border_color(&styleSpin, lv_palette_main(LV_PALETTE_GREY));

		lv_style_init(&styleSpinButtonName);
		lv_style_set_bg_color(&styleSpinButtonName,
				lv_palette_main(LV_PALETTE_BLUE));
		lv_style_set_text_font(&styleSpinButtonName, &SPINBUTTONNAMEFONT);
		c = lv_color_make(0, 0, 255);
		lv_style_set_text_color(&styleSpinButtonName, c);

		lv_style_init(&styleSpinButton);
		lv_style_set_bg_color(&styleSpinButton,
		lv_palette_main(LV_PALETTE_BLUE));
		lv_style_set_text_font(&styleSpinButton, &SPINBUTTONFONT);
		c = lv_color_make(255, 255, 0);
		lv_style_set_text_color(&styleSpinButton, c);
	}

//// name label
	if ( strlen(myDesc.name) >0 ){
		namelabel = lv_label_create ( _parent);//  lv_spinbox_create(parent);
	//	h = SPINBUTTONNAMEFONT.line_height;
	//	lv_obj_set_size(namelabel, LV_HOR_RES_MAX, h+ 3);

		lv_obj_set_pos( namelabel, 20,y);
		lv_label_set_text(namelabel,myDesc.name);
		lv_obj_add_style( namelabel, &styleSpinButtonName,0);
	}

 //value label
	label = lv_label_create ( _parent);//  lv_spinbox_create(parent);

	h = SPINBUTTONFONT.line_height;

	lv_obj_set_size(label, 140,h + 5);
//	lv_obj_set_size(label, 140,spinBoxHeigth);
	if ( strlen(myDesc.name) >0 )
		lv_obj_set_pos( label, (LV_HOR_RES_MAX-140)/2, y +spinBoxButtonHeigth/2 -5);
	else
		lv_obj_set_pos( label, (LV_HOR_RES_MAX-140)/2, y);
	lv_obj_add_style( label, &styleSpin,0);
	lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
	myDesc.label = label;


	buttonP = lv_btn_create(_parent);
	// lv_obj_set_size(btn, h, h);
	lv_obj_set_size(buttonP, spinBoxButtonWidth,  spinBoxButtonHeigth);
	lv_obj_align_to(buttonP, label, LV_ALIGN_OUT_RIGHT_MID, 5, 0);

	lv_obj_t* lbel = lv_label_create(buttonP);
	lv_obj_add_style( lbel, &styleSpinButton,0);
	lv_label_set_text(lbel, "+");
	lv_obj_center(lbel);

	lv_obj_add_style( buttonP, &styleSpinButton,0);
	lv_obj_add_event_cb(buttonP, lv_spinbox_increment_event_cb, LV_EVENT_ALL, this);

	buttonM = lv_btn_create(_parent);
	// lv_obj_set_size(btn, h, h);
	lv_obj_set_size(buttonM,spinBoxButtonWidth, spinBoxButtonHeigth);
	lv_obj_align_to(buttonM, label, LV_ALIGN_OUT_LEFT_MID, -5, 0);

	lbel = lv_label_create(buttonM);
	lv_obj_add_style( lbel, &styleSpinButton,0);
	lv_label_set_text(lbel, "-");
	lv_obj_center(lbel);

	lv_obj_add_style( buttonM, &styleSpinButton,0);
	lv_obj_add_event_cb(buttonM, lv_spinbox_decrement_event_cb, LV_EVENT_ALL, this);

	char str[MAXCHARS+1];
	sprintf( str,myDesc.format, *myDesc.var);
	lv_label_set_text(label,str);
}

SpinBox::~SpinBox() {
	// TODO Auto-generated destructor stub
}


