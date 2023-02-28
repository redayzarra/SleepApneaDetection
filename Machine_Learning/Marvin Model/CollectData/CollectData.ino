// Initialize data collection for all sensors

#include <Wire.h> // Include the necessary libraries to read the data from sensors
#include <Arduino_LSM9DS1.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_APDS9960.h>
#include <Adafruit_LPS22HB.h>
#include <Adafruit_HTS221.h>

// Define the sensors
Adafruit_APDS9960 apds;
Adafruit_LPS22HB lps;
Adafruit_HTS221 hts;

bool isCollectingData = false; // This boolean value checks to see if we should be collecting data

void setup() {
  Serial.begin(9600);