# Homespace Data Acquisition - UML Capstone

## Table of contents

-   [Overview](#overview)
-   [Solution](#solution)
-   [Final Product](#sleep-apnea-detection-system)
-   [Installing Dependencies](#installing-dependencies)
-   [Hardware Setup](#hardware-setup)
-   [User Manual](#user-manual)
-   [License](#license)

## Overview

Welcome to my UML capstone project from [UMass Chan Medical School](https://www.umassmed.edu/), where I delve into the intersection of machine learning, hardware, and web development to create a custom home system for monitoring and improving the health of individuals suffering from sleep apnea. The project aims to develop a home system that can gather data from various sensors installed in a custom device and use that data to understand a patient's daily movement patterns and the presence of sleep apnea. This technology improves the patient's lifestyle by providing them with more accurate and personalized treatment plans, and healthcare professionals with more detailed information about the patient's condition. Through this project, I aim to demonstrate the potential of IoT and TinyML in healthcare and how it influences people's lives. I will be using a combination of hardware and software to create a custom system that can gather data from multiple sources and use that data to build machine-learning models to detect sleep apnea.


### Problem Statement:

There is a lack of objective and quantitative data with regard to homebound patients’ well-being, which results in many patients receiving inadequate support based on their needs. A system that establishes and tracks patterns in a patient’s movement in their home and detects the presence of sleep apnea is needed in order to help medical professionals make more informed decisions for their patients.

### Objective Statement:

The objective is to detect changes in the functional status of homebound patients with neurodegenerative disorders based on their movement around their homes. In addition, this system will detect if the patient suffers from sleep apnea by collecting daily breathing patterns, with the use of algorithms to make inferences based on data, by the end of April 2023.

## Solution

**Sleep Apnea Detection:** Utilizes an Arduino Nano 33 BLE Sense board and a Raspberry Pi as a central data collection hub for sleep detection. The system collects data from various sensors, including temperature, humidity, and color sensors, and analyzes the audio data to determine the number of breaths per minute. Embedded machine learning models, using TinyML technology on the Arduino, recognize specific keywords to control data collection. The Raspberry Pi processes the data and sends it to a MongoDB database for further analysis and storage.
 
<div align="center">

<img src="https://user-images.githubusercontent.com/113388793/214855097-9de0dd4e-f75c-4cd2-baac-8225e80b091e.PNG" >

</div>

<div align = 'center'>

Flowchart for sleep apnea detection - ReDay Z.

</div>

# Sleep Apnea Detection System

This project utilizes an Arduino Nano 33 BLE Sense board to listen for specific voice commands and respond by collecting sensor data. The Arduino board is equipped with a microphone and various sensors, including temperature, humidity, and color sensors. The keyword spotting model is implemented using TensorFlow Lite Micro, which allows the board to recognize specific keywords like "learn" and "stop."

## Installing Dependencies

#### Arduino Nano 33 BLE Sense board
- TensorFlow Lite Micro library
- Arduino_HTS221 library
- Arduino_APDS9960 library
- PDM library

#### Raspberry Pi
- Python
- NumPy
- SciPy
- MongoDB

### Installing Dependencies on Raspberry Pi

1. Update your Raspberry Pi's package list and installing the dependencies by running the following commands:

```bash
sudo apt update

sudo apt install python3 python3-pip

sudo apt install python3-numpy

sudo apt install python3-scipy

sudo apt install -y mongodb
```

### Arduino Command Responder Code Structure

The `arduino_command_responder.cpp` file contains the main code for the Arduino command responder, which consists of the following sections:

1. **Header includes**: The required libraries for the sensors, TensorFlow Lite Micro, and other necessary components are included at the beginning of the file.

2. **Global variables and functions**: Variables and functions are declared to handle data collection, sensor initialization, and data transmission.

3. **Command responder function**: The `RespondToCommand` function is responsible for processing the detected keywords, initializing sensors, and enabling/disabling data collection based on the voice command.

4. **Main setup and loop**: The main `setup()` and `loop()` functions are used to set up the hardware and call the TensorFlow Lite Micro library to listen for keywords and respond accordingly.

Remember to install the necessary libraries and set up the hardware according to the provided instructions to ensure the proper functioning of the Arduino command responder.

## Hardware Setup

### Setting Up the Arduino Nano 33 BLE Sense Board

1. Install the Arduino IDE from the official website: https://www.arduino.cc/en/software

2. Connect the Arduino Nano 33 BLE Sense board to your computer using a USB cable.

3. Open the Arduino IDE, and navigate to `Tools > Board > Boards Manager`. Search for "Arduino Mbed OS Nano Boards" and install the package.

4. Go to `Tools > Board` and select "Arduino Nano 33 BLE."

5. Install the required libraries:
    - TensorFlow Lite Micro library: Navigate to `Sketch > Include Library > Manage Libraries`, search for "TensorFlow Lite Micro" and install the latest version.
    - Arduino_HTS221 library: Search for "Arduino_HTS221" and install the latest version.
    - Arduino_APDS9960 library: Search for "Arduino_APDS9960" and install the latest version.
    - PDM library: Search for "PDM" and install the latest version.

6. Upload the `arduino_command_responder.cpp` file to the Arduino board by clicking the `Upload` button in the Arduino IDE.

### Setting Up the Raspberry Pi

1. Install Raspberry Pi OS on your Raspberry Pi and set up the necessary peripherals (keyboard, mouse, and monitor).

2. Connect the Raspberry Pi to the internet using an Ethernet cable or by configuring Wi-Fi.

3. Install Python and necessary libraries (such as NumPy, SciPy, and MongoDB) on the Raspberry Pi.

4. Connect the Arduino Nano 33 BLE Sense board to the Raspberry Pi using a USB cable.

5. Run the Python script on the Raspberry Pi to start collecting and processing data from the Arduino board.

## User Manual

### Running the System
#### Connect the Arduino to the Raspberry Pi
- Use a micro-USB cable to connect the Arduino Nano 33 BLE Sense to one of the Raspberry Pi's USB ports.
5.3. Log in to the Raspberry Pi
- Select the **Homespace Capstone user** to access the necessary content
- Log into the user account with the password: *homespace123*
#### Connect your Raspberry Pi to a Wi-Fi network
- Power on your Raspberry Pi and wait for it to boot into the Raspberry Pi OS desktop environment.
- In the top-right corner of the screen, you'll find the Wi-Fi icon (it looks like an antenna with radio waves). Click on the Wi-Fi icon to open the Wi-Fi menu.
- A list of available Wi-Fi networks will be displayed. Find your Wi-Fi network's SSID (name) in the list and click on it.
- A window will pop up asking for the Wi-Fi password. Enter the password for your Wi-Fi network and click on the "OK" button.
- Your Raspberry Pi will now attempt to connect to the Wi-Fi network. If the connection is successful, the Wi-Fi icon will change to indicate the connection strength, and you'll see a message saying that the connection has been established.
- To confirm that your Raspberry Pi is connected to the internet, you can open a terminal window and run the following command:
```
ping -c 4 google.com
```
- This command will send four packets to Google's server. If the connection is successful, you'll see responses from the server, indicating that your Raspberry Pi is connected to the internet.
- If you want to view the IP address assigned to your Raspberry Pi on the Wi-Fi network, you can run the following command in the terminal:
```
ifconfig wlan0
```
- Look for the "inet" line, and you'll see the IP address next to it.
#### Start the Python script
- Open a terminal window on the Raspberry Pi and navigate to the directory containing the Python script (e.g., the desktop).
- Run the Python script using the following command:
  ```
  python3 run.py
  ```
### Using the System
- With the Python script running on the Raspberry Pi, the system is now listening for the keywords "learn" and "stop."
- Say the keyword "learn" to start data collection. The Arduino will collect data from the temperature, humidity, color sensors, and the microphone.
- The Raspberry Pi processes the data, including analyzing the audio to determine breaths per minute, and stores the data in a MongoDB database.
- Say the keyword "stop" to stop data collection.
