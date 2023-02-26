// Initialize data collection for all sensors

#include <Wire.h> // Include essential headers for senors and SD card
#include <Arduino_HTS221.h>
#include <Arduino_LPS22HB.h>
#include <Arduino_APDS9960.h>
#include <Arduino_LSM9DS1.h>
#include <SD.h>

File dataFile;

void setup() {

  Serial.begin(9600);
  while (!Serial) {}

  if (!HTS.begin()) {
    Serial.println("Failed to initialize HTS sensor!"); // Give a warning if HTS Sensor fails
    while (1);
  }

  if (!LPS22HB.begin()) {
    Serial.println("Failed to initialize LPS sensor!"); // Give a warning if LPS Sensor fails
    while (1);
  }

  if (!APDS9960.begin()) {
    Serial.println("Failed to initialize APDS sensor!"); // Give a warning if APDS Sensor fails
    while (1);
  }

  if (!IMU.begin()) {
    Serial.println("Failed to initialize LSM sensor!"); // Give a warning if LSM Sensor fails
    while (1);
  }

  if (!SD.begin(4)) {
    Serial.println("Failed to initialize SD card!"); // Give a warning if SD Card fails
    while (1);
  }