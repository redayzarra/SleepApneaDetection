// DHT22 Temp & Humidity Sensor - Data Collection

#include <SD.h> // Include the SD library
#include <DHT.h> // Include the DHT library
const int DHT_PIN = 2; // Connect the DHT22 sensor to digital pin 2
const int chipSelect = 10; // Chip select pin for the SD card
DHT dht(DHT_PIN, DHT22); // Initialize the DHT object
File dataFile; // Create a File object

// SD card must be formatted as FAT16 or FAT32 and must be connected to the chipSelect pin and the 3.3V pin. 
// Also make sure that the library is correctly installed and the board is compatible with SD card module.


void setup() {

  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  dht.begin(); // Initialize the DHT sensor

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

  dataFile.print("Temperature,Humidity"); // Column headers for the .csv file
  dataFile.println();
}

void loop() {
  float temperature = dht.readTemperature(); // Read the temperature from the DHT22 sensor
  float humidity = dht.readHumidity(); // Read the humidity from the DHT22 sensor

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" Humidity: ");
  Serial.println(humidity); // Send the values to the serial monitor
  
  // Write the values to the .csv file
  dataFile.print(temperature);
  dataFile.print(",");
  dataFile.print(humidity);
  dataFile.println();
  delay(2000); // Wait for 2 seconds
}

void exit() {
  dataFile.close(); // Close the file when the program exits
}