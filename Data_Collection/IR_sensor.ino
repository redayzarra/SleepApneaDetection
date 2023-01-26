// Sharp IR Distance Sensor

#include <SD.h> // Include the SD library
const int IR_PIN = A0; // Connect the SHARP IR distance sensor to analog pin A0
const int chipSelect = 10; // Chip select pin for the SD card
File dataFile; // Create a File object

// SD card must be formatted as FAT16 or FAT32 and must be connected to the chipSelect pin and the 3.3V pin. 
// Also make sure that the library is correctly installed and the board is compatible with SD card module.

void setup() {

  Serial.begin(9600); // Initialize serial communication at 9600 baud rate

  // Initialize the SD card
  pinMode(chipSelect, OUTPUT);
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed");
    return;
  }

  // Create a new file on the SD card
  dataFile = SD.open("data.csv", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Error creating file");
    return;
  }

  dataFile.print("Distance"); // Column headers for the .csv file
  dataFile.println();
}

void loop() {
  
  int distance = analogRead(IR_PIN); // Read the value from the SHARP IR distance sensor

  //Convert the analog reading (which goes from 0 - 1023) to distance in cm (0 - 80)
  distance = map(distance, 0, 1023, 0, 80);
  Serial.print("Distance: ");
  Serial.println(distance); // Send the value to the serial monitor

  // Write the value to the .csv file
  dataFile.print(distance);
  dataFile.println();
  delay(100); // Wait for 100 milliseconds
}

void exit() {
  dataFile.close(); // Close the file when the program exits
}