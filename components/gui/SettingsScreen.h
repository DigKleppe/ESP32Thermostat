/*
 * SettingsScreen.h
 *
 *  Created on: Mar 20, 2022
 *      Author: dig
 */

#ifndef GUI_SETTINGSSCREEN_H_
#define GUI_SETTINGSSCREEN_H_

#include "SpinBox.h"
#include "NavigArrows.h"
#include "backGround.h"

const int NR_SPINBOXES =  4;

class SettingsScreen {
public:
	SettingsScreen( const SpinBoxDescr_t * descr);
	virtual ~SettingsScreen();
	void upDate( void);
	void show();
private:
	lv_obj_t * backGround;
	SpinBox * spinBox[NR_SPINBOXES];
	NavigArrows * navigArrows;
	lv_obj_t * settingsScreen;


};

#endif /* GUI_SETTINGSSCREEN_H_ */
