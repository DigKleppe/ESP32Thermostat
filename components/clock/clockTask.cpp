/*
 * Clock.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: dig
 */

#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_sntp.h"
#include "ClockDisplay.h"

struct tm timeinfo;
static const char *TAG = "Clock";


#define MAXDISPLAYS 5
ClockDisplay * clockToUpdate[MAXDISPLAYS];
int clockDisplays;

void registerTimeUpdate( ClockDisplay * p ) {
	if ( clockDisplays < MAXDISPLAYS)
		clockToUpdate[clockDisplays++] = p;
	else
	    ESP_LOGE(TAG, "Maximum number clockDisplays reached");
}


static void initialize_sntp(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_init();
}


void clockTask(void *pvParameter) {
	int lastsec = -1;
	char strftime_buf[64];
	ClockDisplay * pd;

    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3",1);
    tzset();

    initialize_sntp();

    time_t now = 0;
    int retry = 0;
    const int retry_count = 20;
    while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET ) {//  && ++retry < retry_count) {
        ESP_LOGI(TAG, "Waiting for system time to be set... );// (%d/%d)", retry, retry_count);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }

    do {
    	 time(&now);
    	 localtime_r(&now, &timeinfo);
    	 if (lastsec != timeinfo.tm_sec ) {
    		 lastsec = timeinfo.tm_sec;
    	//	 strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    	//	 ESP_LOGI(TAG, "The current date/time is: %s", strftime_buf);
    		 sprintf(strftime_buf,"%2d:%02d:%02d" , timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    		 for ( int n=0 ; n < clockDisplays;n++){
    			 pd =  clockToUpdate[n];
    		     pd->setText(strftime_buf);
    		 }
    	 }
    	 vTaskDelay(200/portTICK_PERIOD_MS );
    } while (1);

}



