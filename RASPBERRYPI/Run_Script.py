# This file will need to be running to establish connection with MongoDB,
# and process and transfer data and audio to the database.
# RASPBERRY PI 3 - MODEL B

import serial
import pymongo
from pymongo import MongoClient
import time
import numpy as np
from scipy.signal import butter, lfilter, find_peaks

# AUDIO PROCESSING - Bandpass filter functions: These filters are trying to only keep breathing noises.
def butter_bandpass(lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype='band')
    return b, a

def butter_bandpass_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandpass(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y

def process_audio_for_breathing(audio_data, sample_rate=16000):
    # Define the breathing frequency range (0.1 to 0.5 Hz) - Adjust this value based on your own data. These are generic values based on my research.
    lowcut = 0.1
    highcut = 0.5

    # Apply the bandpass filter
    filtered_signal = butter_bandpass_filter(audio_data, lowcut, highcut, sample_rate)

    return filtered_signal

# CALCULATING BREATHS PER MINUTE - Using the find_peaks algorithm
def calculate_breaths_per_minute(filtered_signal, sample_rate, min_peak_height=0.01, min_peak_distance=0.5):
    # Detect peaks in the filtered signal
    min_distance = int(sample_rate * min_peak_distance)
    peaks, _ = find_peaks(filtered_signal, height=min_peak_height, distance=min_distance)

    # Calculate breaths per minute
    if len(peaks) > 1:
        breath_duration = np.mean(np.diff(peaks)) / sample_rate
        breaths_per_minute = 60 / breath_duration
    else:
        breaths_per_minute = 0

    return breaths_per_minute

# MongoDB configuration - The following are credentials to connect to MongoDB
MONGODB_CONNECTION_STRING = 'mongodb+srv://<username>:<password>@<cluster_url>/test?retryWrites=true&w=majority'
client = MongoClient(MONGODB_CONNECTION_STRING)
db = client['your_database_name'] # This is the database name
collection = db['your_collection_name'] # This is the collection name

ser = serial.Serial('/dev/ttyACM0', 9600)  # You may need to adjust the port depending on your setup

audio_buffer = []
buffer_size = 16000  # Adjust this value based on the desired buffer size. This processes one second of audio at a time (assuming a sample rate of 16,000 Hz).

while True:
    try:
        data = ser.readline().decode().strip()
        print("Received data:", data)

        if data.startswith("Temperature:"):
            # Assuming data is in the format: "Temperature: xx.x Humidity: xx.x R: xxx G: xxx B: xxx"
            data_list = data.split(' ')

            if len(data_list) == 12:
                temp = float(data_list[1])
                humidity = float(data_list[3])
                r = int(data_list[5])
                g = int(data_list[7])
                b = int(data_list[9])

                # Prepare the data for MongoDB
                data_to_insert = {
                    "temperature": temp,
                    "humidity": humidity,
                    "r": r,
                    "g": g,
                    "b": b,
                    "timestamp": time.time()
                }

    except Exception as e:
        print("Error:", e)