ESP32thermostat app
====================

OTA simple
The bootlader_1 partition must be loaded first.
 
Use the partitionsOTA_4M for 1 OTA partition in the user software.
The bootloader checks the MD5 of the present program in the factory partition.
If OK The user program is executed.

In the build folder start phyton fileserver:

python3 -m http.server 8070

The firmwareversion binairy name must match the one in the condifuration file 
in the SDK configuration

# Firmware_Storage Upgrade Configuration
#
CONFIG_DEFAULT_FIRMWARE_UPGRADE_URL="http://192.168.2.1:8070/"
CONFIG_FIRMWARE_UPGRADE_FILENAME="thermostaat.bin"
CONFIG_SPIFFS_UPGRADE_FILENAME="storageThermostaat.bin"
CONFIG_SPIFFS_INFO_FILENAME="storageVersionThermostaat.txt"

The firmware knows its current version, and reads the firmware file on the server.
If it is not the same the new binary is flashed by the bootloader.


Updating SPIFFS image:

Copy the generated image to the build folder and change the name to CONFIG_SPIFFS_UPGRADE_FILENAME

In the build folder a textfile CONFIG_SPIFFS_INFO_FILENAME containing only the version of the spiffs must be present. EG "1.2" 

if this version differs from the last flashed version the CONFIG_SPIFFS_UPGRADE_FILENAME is downloaded from the fileserver.


