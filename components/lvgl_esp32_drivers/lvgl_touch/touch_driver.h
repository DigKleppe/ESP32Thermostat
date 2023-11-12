/**
 * @file touch_driver.h
 */

#ifndef TOUCH_DRIVER_H
#define TOUCH_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stdbool.h>
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#if defined (CONFIG_LV_TOUCH_CONTROLLER_XPT2046)
#include "../../lvgl_esp32_drivers/lvgl_touch/xpt2046.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT6X06)
#include "../../lvgl_esp32_drivers/lvgl_touch/ft6x36.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_STMPE610)
#include "../../lvgl_esp32_drivers/lvgl_touch/stmpe610.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_ADCRAW)
#include "../../lvgl_esp32_drivers/lvgl_touch/adcraw.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT81X)
#include "../../lvgl_esp32_drivers/lvgl_touch/FT81x.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_RA8875)
#include "../../lvgl_esp32_drivers/lvgl_touch/ra8875_touch.h"
#endif

/*********************
*      DEFINES
*********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void touch_driver_init(void);
void touch_driver_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* TOUCH_DRIVER_H */

