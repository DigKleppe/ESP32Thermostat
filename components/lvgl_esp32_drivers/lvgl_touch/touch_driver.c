/**
 * @file touch_driver.c
 */

#include "../../lvgl_esp32_drivers/lvgl_touch/touch_driver.h"

#include "../../lvgl_esp32_drivers/lvgl_touch/tp_i2c.h"
#include "../../lvgl_esp32_drivers/lvgl_touch/tp_spi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

//#define USE_SEMPHORE
#ifdef USE_SEMPHORE
extern SemaphoreHandle_t I2CSemaphore;  // used by lvgl, shares the same bus
#endif

void touch_driver_init(void) {
#ifdef USE_SEMPHORE
	if (pdTRUE == xSemaphoreTake(I2CSemaphore, portMAX_DELAY)) {
#endif

#if defined (CONFIG_LV_TOUCH_CONTROLLER_XPT2046)
    xpt2046_init();
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT6X06)
		ft6x06_init(FT6236_I2C_SLAVE_ADDR);
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_STMPE610)
    stmpe610_init();
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_ADCRAW)
    adcraw_init();
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT81X)
    /* nothing to do */
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_RA8875)
    ra8875_touch_init();
#endif
#ifdef USE_SEMPHORE

	if (pdTRUE == xSemaphoreTake(I2CSemaphore, portMAX_DELAY)) {
		xSemaphoreGive(I2CSemaphore);
	}
	}
#endif

}

void touch_driver_read(lv_indev_drv_t *drv, lv_indev_data_t *data) {
	//ol res = false;
#ifdef USE_SEMPHORE
	if (pdTRUE == xSemaphoreTake(I2CSemaphore, portMAX_DELAY)) {
#endif
#if defined (CONFIG_LV_TOUCH_CONTROLLER_XPT2046)
   xpt2046_read(drv, data);
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT6X06)
	ft6x36_read(drv, data);
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_STMPE610)
    res = stmpe610_read(drv, data);
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_ADCRAW)
    res = adcraw_read(drv, data);
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT81X)
    res = FT81x_read(drv, data);
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_RA8875)
    res = ra8875_touch_read(drv, data);
#endif

#ifdef USE_SEMPHORE
	xSemaphoreGive(I2CSemaphore);
}
#endif
//  return res;
}

