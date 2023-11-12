/**
 * @file disp_driver.h
 */

#ifndef DISP_DRIVER_H
#define DISP_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9341
#include "../../lvgl_esp32_drivers/lvgl_tft/ili9341.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9481
#include "../../lvgl_esp32_drivers/lvgl_tft/ili9481.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9488
#include "../../lvgl_esp32_drivers/lvgl_tft/ili9488.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7789
#include "../../lvgl_esp32_drivers/lvgl_tft/st7789.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7796S
#include "../../lvgl_esp32_drivers/lvgl_tft/st7796s.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S
#include "../../lvgl_esp32_drivers/lvgl_tft/st7735s.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_HX8357
#include "../../lvgl_esp32_drivers/lvgl_tft/hx8357.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_HX8347
#include "hx8347.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9486
#include "../../lvgl_esp32_drivers/lvgl_tft/ili9486.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SH1107
#include "../../lvgl_esp32_drivers/lvgl_tft/sh1107.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306
#include "../../lvgl_esp32_drivers/lvgl_tft/ssd1306.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_FT81X
#include "../../lvgl_esp32_drivers/lvgl_tft/FT81x.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820
#include "../../lvgl_esp32_drivers/lvgl_tft/il3820.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_RA8875
#include "../../lvgl_esp32_drivers/lvgl_tft/ra8875.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_GC9A01
#include "../../lvgl_esp32_drivers/lvgl_tft/GC9A01.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A
#include "../../lvgl_esp32_drivers/lvgl_tft/jd79653a.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D
#include "../../lvgl_esp32_drivers/lvgl_tft/uc8151d.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/* Initialize display */
void disp_driver_init(void);

/* Display flush callback */
void disp_driver_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_map);

/* Display rounder callback, used with monochrome dispays */
void disp_driver_rounder(lv_disp_drv_t * disp_drv, lv_area_t * area);

/* Display set_px callback, used with monochrome dispays */
void disp_driver_set_px(lv_disp_drv_t * disp_drv, uint8_t * buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y,
    lv_color_t color, lv_opa_t opa);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*DISP_DRIVER_H*/
