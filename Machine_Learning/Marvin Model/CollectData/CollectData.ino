// Initialize data collection for all sensors

#include <Wire.h> // Include essential headers for senors and SD card
#include <Arduino_HTS221.h>
#include <Arduino_LPS22HB.h>
#include <Arduino_APDS9960.h>
#include <Arduino_LSM9DS1.h>
#include <SD.h>

File dataFile;

void setup() {