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
  while (!Serial); // Wait for Serial Monitor to open

  // Set up the APDS9960 sensor - Light and Proximity Sensor
  if (!apds.begin()) {
    Serial.println("Failed to initialize APDS9960");
    while (1);
  }

  apds.enableGestureSensor(false); // Disable the gesture feature from the sensor
  apds.enableLightSensor(true); // Enable the light and proximity features
  apds.enableProximitySensor(true);


  // Set up the LPS22HB sensor - Barometric Pressure
  if (!lps.begin()) {
    Serial.println("Failed to initialize LPS22HB");
    while (1);
  }

  // Set up the HTS221 sensor
  if (!hts.begin()) {
    Serial.println("Failed to initialize HTS221");
    while (1);
  }
}
