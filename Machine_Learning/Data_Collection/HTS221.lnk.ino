//HTS221 Temperature and Humidity Collection - Data Collection

#include <Wire.h>
#include <Arduino_HTS221.h>
#include <SD.h>

File dataFile;

void setup() {
  Serial.begin(9600);
  