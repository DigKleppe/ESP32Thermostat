 Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )
#set(COMPONENT_SRCS "*.c")
set(COMPONENT_SRCDIRS ".")
set(COMPONENT_ADD_INCLUDEDIRS "include")
register_component()
spiffs_create_partition_image(storage ../spiffs_image FLASH_IN_PROJECT)

