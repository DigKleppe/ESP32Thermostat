/*
 * guiTask.h
 *
 *  Created on: Apr 14, 2021
 *      Author: dig
 */

#ifndef COMPONENTS_GUI_GUICOMMONTASK_H_
#define COMPONENTS_GUI_GUICOMMONTASK_H_

#include "lvgl.h"

extern "C" {


#ifdef LGL_SIMULATOR
#include "lv_drv_conf.h"
#define LV_HOR_RES_MAX 	SDL_HOR_RES
#define LV_VER_RES_MAX SDL_VER_RES
#else
	#include "freertos/FreeRTOS.h"
	#include "freertos/task.h"
	#include "freertos/semphr.h"

	#include "../lvgl_esp32_drivers/lvgl_helpers.h"
	extern SemaphoreHandle_t xGuiSemaphore;
#endif

void guiCommonTask(void *pvParameter);
//extern lv_indev_t *kb_indev;

void setBacklight ( int percent);


extern volatile bool displayReady;
}

#endif /* COMPONENTS_GUI_GUICOMMONTASK_H_ */
