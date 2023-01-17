#include <SD.h> // Include the SD library
const int LDR_PIN = A0; // Connect the LDR to analog pin A0
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
}

void loop() {

  int ldrValue = analogRead(LDR_PIN); // Read the value from the LDR

  Serial.println(ldrValue); // Send the value to the serial monitor
  
  // Write the value to the .csv file
  dataFile.print(ldrValue);
  dataFile.print(",");
  delay(100); // Wait for 100 milliseconds
}

void exit() {
  dataFile.close(); // Close the file when the program exits
}