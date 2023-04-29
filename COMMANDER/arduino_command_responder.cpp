/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#if defined(ARDUINO) && !defined(ARDUINO_ARDUINO_NANO33BLE)
#define ARDUINO_EXCLUDE_CODE
#endif  // defined(ARDUINO) && !defined(ARDUINO_ARDUINO_NANO33BLE)

#ifndef ARDUINO_EXCLUDE_CODE

#include "command_responder.h"
#include "Arduino.h"

// Include the required headers for the sensors
#include <Arduino_HTS221.h>   // Temperature and Humidity sensor
#include <Arduino_APDS9960.h> // Color sensor
#include <PDM.h>

// Flag to control data collection
bool collect_data = false;

// Set up the data collection function
void collect_and_send_data() {
  // Collect data from the sensors
  float temperature = HTS.readTemperature();
  float humidity = HTS.readHumidity();

  int r, g, b;
  APDS.readColor(r, g, b); // Read color from the APDS9960 sensor

  // Send data to the Raspberry Pi via Serial
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" Humidity: ");
  Serial.print(humidity);
  Serial.print(" R: ");
  Serial.print(r);
  Serial.print(" G: ");
  Serial.print(g);
  Serial.print(" B: ");
  Serial.println(b);
}

void onPDMdata() {
  // Handle audio data from the microphone
  int bytesAvailable = PDM.available();

  // Read the audio data
  int16_t sampleBuffer[bytesAvailable];
  PDM.read(sampleBuffer, bytesAvailable);

  // Send audio data to the Raspberry Pi via Serial
  for (int i = 0; i < bytesAvailable; i++) {
    Serial.print("Audio: ");
    Serial.println(sampleBuffer[i]);
  }
}

void RespondToCommand(tflite::ErrorReporter* error_reporter,
                      int32_t current_time, const char* found_command,
                      uint8_t score, bool is_new_command) {
  static bool is_initialized = false;
  if (!is_initialized) {
    // Setup Serial communication
    Serial.begin(9600);
    while (!Serial) {
      ;  // wait for Serial to be available
    }

    // Initialize the sensors
    if (!HTS.begin()) {
      Serial.println("Failed to initialize humidity sensor!");
      while (1);
    }

    if (!APDS.begin()) {
      Serial.println("Failed to initialize gesture sensor!");
      while (1);
    }

    // Initialize the microphone
    if (!PDM.begin(1, 16000)) {
      Serial.println("Failed to initialize the microphone!");
      while (1);
    }
    PDM.onReceive(onPDMdata);
    PDM.setGain(20);

    is_initialized = true;
  }

  static int32_t last_command_time = 0;
  static int count = 0;
  static int certainty = 220;

  // Check if a new command is detected
  if (is_new_command) {
    TF_LITE_REPORT_ERROR(error_reporter, "Heard %s (%d) @%dms", found_command,
                         score, current_time);

    // Enable or disable data collection based on the command
    if (found_command[0] == 'l') {
      collect_data = true; // If the "learn" keyword is detected, start data collection
    }
    if (found_command[0] == 's') {
      collect_data = false; // If the "stop" keyword is detected, stop data collection
    }
    if (found_command[0] == 'u') {
      last_command_time = current_time;
      digitalWrite(LEDB, LOW);  // Led flashes blue for unknown
    }
  }

  // If data collection is enabled, collect and send the data
  if (collect_data) {
    collect_and_send_data();
  }
}

#endif  // ARDUINO_EXCLUDE_CODE