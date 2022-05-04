set(COMPONENT_SRCDIRS ".")
set(COMPONENT_ADD_INCLUDEDIRS "include")
#set(COMPONENT_PRIV_REQUIRES  "klp"  "esp_adc_cal" "spiffs" "nvs_flash" "gui" "lvgl" )
register_component()
spiffs_create_partition_image(storage ../spiffs_image FLASH_IN_PROJECT)

