import serial
import pymongo
from pymongo import MongoClient
import time
import numpy as np
from scipy.signal import butter, lfilter

# Bandpass filter functions
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
    # Define the breathing frequency range (0.1 to 0.5 Hz)
    lowcut = 0.1
    highcut = 0.5

    # Apply the bandpass filter
    filtered_signal = butter_bandpass_filter(audio_data, lowcut, highcut, sample_rate)

    return filtered_signal
