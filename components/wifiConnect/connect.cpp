/**
Connect starts wifi, tries to make contact with previous accesspoint.
if the AP cannot be found smartConfig is invoked for SMARTCONFIGTIMEOUT seconds.
without succes the process is contuously repeated
Webserver is started
DNS server is started ( name in sdkconfig )  website can be reached as eg http://esp32-mdns.local/
todo make  things configurable in sdkconfig

settings ssidd and pwd are stored in nvsFlash
 */

#include <string.h>
#include "sdkconfig.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "esp_wifi_default.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_smartconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "lwip/err.h"
#include "lwip/sys.h"

#include "nvs_flash.h"
#include "nvs.h"
#include "mdns.h"
#include "netdb.h"
#include "connect.h"

#define EXAMPLE_DO_CONNECT CONFIG_EXAMPLE_CONNECT_WIFI || CONFIG_EXAMPLE_CONNECT_ETHERNET

#if CONFIG_EXAMPLE_WIFI_SCAN_METHOD_FAST
#define EXAMPLE_WIFI_SCAN_METHOD WIFI_FAST_SCAN
#elif CONFIG_EXAMPLE_WIFI_SCAN_METHOD_ALL_CHANNEL
#define EXAMPLE_WIFI_SCAN_METHOD WIFI_ALL_CHANNEL_SCAN
#endif

#if CONFIG_EXAMPLE_WIFI_CONNECT_AP_BY_SIGNAL
#define EXAMPLE_WIFI_CONNECT_AP_SORT_METHOD WIFI_CONNECT_AP_BY_SIGNAL
#elif CONFIG_EXAMPLE_WIFI_CONNECT_AP_BY_SECURITY
#define EXAMPLE_WIFI_CONNECT_AP_SORT_METHOD WIFI_CONNECT_AP_BY_SECURITY
#endif

#if CONFIG_EXAMPLE_WIFI_AUTH_OPEN
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_OPEN
#elif CONFIG_EXAMPLE_WIFI_AUTH_WEP
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WEP
#elif CONFIG_EXAMPLE_WIFI_AUTH_WPA_PSK
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_PSK
#elif CONFIG_EXAMPLE_WIFI_AUTH_WPA2_PSK
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_PSK
#elif CONFIG_EXAMPLE_WIFI_AUTH_WPA_WPA2_PSK
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_WPA2_PSK
#elif CONFIG_EXAMPLE_WIFI_AUTH_WPA2_ENTERPRISE
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_ENTERPRISE
#elif CONFIG_EXAMPLE_WIFI_AUTH_WPA3_PSK
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA3_PSK
#elif CONFIG_EXAMPLE_WIFI_AUTH_WPA2_WPA3_PSK
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_WPA3_PSK
#elif CONFIG_EXAMPLE_WIFI_AUTH_WAPI_PSK
#define EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WAPI_PSK
#endif


#define SMARTCONFIGTIMEOUT	60 // seconds to wait smartConfig, before switching to previous network
#define CONNECTRETRIES 		5 // before switching to smartconfig

static const char *TAG = "connect";

static const int CONNECTED_BIT = BIT0;
static const int DISCONNECTED_BIT = BIT1;
static const int ESPTOUCH_DONE_BIT = BIT2;

void initialiseMdns(void);
esp_err_t saveWifiSettings(void);
esp_err_t loadWifiSettings(void);

//wifiSettings_t wifiSettings = { { .SSID = "ESP32" }, { .pwd = "ESP32" }, .updated = false };
wifiSettings_t wifiSettings = { { .SSID = "Klepnet" }, { .pwd = "Yellowstone1999" }, .updated = false };
static esp_netif_t *wifiNetif = NULL;
static bool connected = false;
static EventGroupHandle_t s_wifi_event_group;

esp_netif_t* wifi_start(void);

static void wifi_stop(void);
esp_err_t start_file_server(const char *base_path);
char myIP[17] = {"not assigned"};


static void event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
	if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
		//xTaskCreate(smartconfigTtask, "smartconfigTtask", 4096, NULL, 3, NULL);
	} else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
		//	if (state == 0)
		//		esp_wifi_connect();
		xEventGroupClearBits(s_wifi_event_group, CONNECTED_BIT);
		xEventGroupSetBits(s_wifi_event_group, DISCONNECTED_BIT);
		connected = false;
	} else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
		xEventGroupSetBits(s_wifi_event_group, CONNECTED_BIT);
		xEventGroupClearBits(s_wifi_event_group, DISCONNECTED_BIT);
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        sprintf( myIP,IPSTR, IP2STR(&event->ip_info.ip));
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));

		connected = true;
	} else if (event_base == SC_EVENT && event_id == SC_EVENT_SCAN_DONE) {
		ESP_LOGI(TAG, "Scan done");
	} else if (event_base == SC_EVENT && event_id == SC_EVENT_FOUND_CHANNEL) {
		ESP_LOGI(TAG, "Found channel");
	} else if (event_base == SC_EVENT && event_id == SC_EVENT_GOT_SSID_PSWD) {
		ESP_LOGI(TAG, "Got SSID and password");

		smartconfig_event_got_ssid_pswd_t *evt = (smartconfig_event_got_ssid_pswd_t*) event_data;
		wifi_config_t wifi_config;
		uint8_t ssid[33] = { 0 };
		uint8_t password[65] = { 0 };
		uint8_t rvd_data[33] = { 0 };

		bzero(&wifi_config, sizeof(wifi_config_t));
		memcpy(wifi_config.sta.ssid, evt->ssid, sizeof(wifi_config.sta.ssid));
		memcpy(wifi_config.sta.password, evt->password, sizeof(wifi_config.sta.password));

		memcpy(wifiSettings.SSID, evt->ssid, sizeof(wifi_config.sta.ssid));
		memcpy(wifiSettings.pwd, evt->password, sizeof(wifi_config.sta.password));
		wifiSettings.updated = true;

		wifi_config.sta.bssid_set = evt->bssid_set;
		if (wifi_config.sta.bssid_set == true) {
			memcpy(wifi_config.sta.bssid, evt->bssid, sizeof(wifi_config.sta.bssid));
		}

		memcpy(ssid, evt->ssid, sizeof(evt->ssid));
		memcpy(password, evt->password, sizeof(evt->password));
		ESP_LOGI(TAG, "SSID:%s", ssid);
		ESP_LOGI(TAG, "PASSWORD:%s", password);
		if (evt->type == SC_TYPE_ESPTOUCH_V2) {
			ESP_ERROR_CHECK(esp_smartconfig_get_rvd_data(rvd_data, sizeof(rvd_data)));
			ESP_LOGI(TAG, "RVD_DATA:");
			for (int i = 0; i < 33; i++) {
				printf("%02x ", rvd_data[i]);
			}
			printf("\n");
		}

		ESP_ERROR_CHECK(esp_wifi_disconnect());
		ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
		esp_wifi_connect();
		connected = true;

	} else if (event_base == SC_EVENT && event_id == SC_EVENT_SEND_ACK_DONE) {
		xEventGroupSetBits(s_wifi_event_group, ESPTOUCH_DONE_BIT);

	}
}

/* tear down connection, release resources */
static void stop(void) {
	wifi_stop();
}
esp_netif_t* wifi_start(void) {
	char *desc;
	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ESP_ERROR_CHECK(esp_wifi_init(&cfg));

	esp_netif_inherent_config_t esp_netif_config = ESP_NETIF_INHERENT_DEFAULT_WIFI_STA();

	asprintf(&desc, "%s: %s", TAG, esp_netif_config.if_desc);
	esp_netif_config.if_desc = desc;
	esp_netif_config.route_prio = 128;

	esp_netif_t *netif = esp_netif_create_wifi(WIFI_IF_STA, &esp_netif_config);

	free(desc);
	esp_wifi_set_default_wifi_sta_handlers();

	ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
	wifi_config_t wifi_config;
	memset(&wifi_config, 0, sizeof(wifi_config_t));

	strcpy((char*) wifi_config.sta.ssid, wifiSettings.SSID);
	strcpy((char*) wifi_config.sta.password, wifiSettings.pwd);

	wifi_config.sta.scan_method = EXAMPLE_WIFI_SCAN_METHOD;
	wifi_config.sta.sort_method = EXAMPLE_WIFI_CONNECT_AP_SORT_METHOD;
	wifi_config.sta.threshold.rssi = CONFIG_EXAMPLE_WIFI_SCAN_RSSI_THRESHOLD;
	wifi_config.sta.threshold.authmode = EXAMPLE_WIFI_SCAN_AUTH_MODE_THRESHOLD;

	ESP_LOGI(TAG, "Connecting to %s...", wifi_config.sta.ssid);
	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
	ESP_ERROR_CHECK(esp_wifi_start());
	ESP_ERROR_CHECK(esp_wifi_connect());
	return netif;
}

void connectTask(void *parm) {
	EventBits_t uxBits;
	int retries = CONNECTRETRIES;

	loadWifiSettings();
	ESP_ERROR_CHECK(esp_event_loop_create_default());
	s_wifi_event_group = xEventGroupCreate();

	ESP_ERROR_CHECK(esp_register_shutdown_handler(&stop));
	ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL));
	ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL));
	ESP_ERROR_CHECK(esp_event_handler_register(SC_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL));

	ESP_ERROR_CHECK(esp_netif_init());
	wifiNetif = wifi_start();

	ESP_ERROR_CHECK(esp_smartconfig_set_type(SC_TYPE_ESPTOUCH));
	smartconfig_start_config_t smartCfgcfg = SMARTCONFIG_START_CONFIG_DEFAULT();

	initialiseMdns();
	ESP_ERROR_CHECK(start_file_server("/spiffs"));

	ESP_LOGI(TAG, "Waiting for IP");

	while (1) {

		uxBits = xEventGroupWaitBits(s_wifi_event_group, CONNECTED_BIT | DISCONNECTED_BIT | ESPTOUCH_DONE_BIT, true, false, (SMARTCONFIGTIMEOUT * 1000) / portTICK_PERIOD_MS);

		if (uxBits & CONNECTED_BIT) {
			ESP_LOGI(TAG, "WiFi Connected to ap");
		}
		if (uxBits & DISCONNECTED_BIT) {
			if (retries > 0) {
				retries--;
				ESP_LOGI(TAG, "Wi-Fi disconnected, trying to reconnect...");
				esp_err_t err = esp_wifi_connect();
				ESP_ERROR_CHECK(err);
			} else {
				if (retries == 0) {
					ESP_ERROR_CHECK(esp_smartconfig_start(&smartCfgcfg));
					retries--;
				}
			}
			if (uxBits & ESPTOUCH_DONE_BIT) {
				ESP_LOGI(TAG, "smartconfig over");
				esp_smartconfig_stop();
				if (wifiSettings.updated) {
					saveWifiSettings();
					wifiSettings.updated = false;
				}
				retries = CONNECTRETRIES;
			}
		}
		if (uxBits == 0) { // timeout
			if (!connected) {
				ESP_LOGI(TAG, "smartconfig timeout");
				esp_smartconfig_stop();
				retries = CONNECTRETRIES;
				esp_err_t err = esp_wifi_connect();
				ESP_ERROR_CHECK(err);
			}
		}
	}
}

esp_netif_t* get_example_netif_from_desc(const char *desc) {
	esp_netif_t *netif = NULL;
	char *expected_desc;
	asprintf(&expected_desc, "%s: %s", TAG, desc);
	while ((netif = esp_netif_next(netif)) != NULL) {
		if (strcmp(esp_netif_get_desc(netif), expected_desc) == 0) {
			free(expected_desc);
			return netif;
		}
	}
	free(expected_desc);
	return netif;
}

static void wifi_stop(void) {
	esp_netif_t *wifi_netif = get_example_netif_from_desc("sta");

	ESP_ERROR_CHECK(esp_event_handler_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler));
	ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler));
	ESP_ERROR_CHECK(esp_event_handler_unregister(SC_EVENT, ESP_EVENT_ANY_ID, &event_handler));
	esp_err_t err = esp_wifi_stop();
	if (err == ESP_ERR_WIFI_NOT_INIT) {
		return;
	}
	ESP_ERROR_CHECK(err);
	ESP_ERROR_CHECK(esp_wifi_deinit());
	ESP_ERROR_CHECK(esp_wifi_clear_default_wifi_driver_and_handlers(wifi_netif));
	esp_netif_destroy(wifi_netif);
}

esp_err_t saveWifiSettings(void) {
	FILE *fd = fopen("/spiffs/wifisettings", "wb");
	if (fd == NULL) {
		printf("  Error opening file (%d) %s\n", errno, strerror(errno));
		printf("\n");

		return -1;
	}
	int len = sizeof(wifiSettings);
	int res = fwrite(&wifiSettings, 1, len, fd);
	if (res != len) {
		printf("  Error writing to file(%d <> %d\n", res, len);
		res = fclose(fd);
		return -1;
	}
	res = fclose(fd);
	return 0;
}

esp_err_t loadWifiSettings() {
	esp_err_t res = 0;
//	return res;
//#warning wifisettings overruled
	FILE *fd = fopen("/spiffs/wifisettings", "rb");
	if (fd == NULL) {
		printf("  Error opening settings file (%d) %s\n", errno, strerror(errno));

	} else {
		int len = sizeof(wifiSettings);
		res = fread(&wifiSettings, 1, len, fd);
		if (res <= 0) {
			printf("  Error reading from file\n");
		}
		res = fclose(fd);
	}
	return res;
}
void  connect(TaskHandle_t * p) {
	xTaskCreate(connectTask, "connectTask", 4096, NULL, 3, p);
}
