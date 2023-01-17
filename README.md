# Homespace Data Acquisition - UML Capstone

## Overview

Welcome to my UML capstone project, where I delve into the intersection of machine learning, hardware, and web development to create a custom home system for monitoring and improving the health of individuals suffering from sleep apnea. The project aims to develop home system that can gather data from various sensors installed in a custom device and use that data to understand a patient's daily movement patterns and presence of sleep apnea. This technology improves the patient's lifestyle by providing them with more accurate and personalized treatment plans, and healthcare professionals with more detailed information about the patient's condition. Through this project, I aim to demonstrate the potential of IoT's and TinyML in healthcare and how it influences people's lives. I will be using a combination of hardware and software to create a custom system that can gather data from multiple sources and use that data to build machine learning models to detect sleep apnea.

### Problem Statement:

There is a lack of objective and quantitative data with regards to homebound patients well-being, which results in many patients receiving inadequate support based on their needs. A system that establishes and tracks patterns in a patient’s movement in their home and detects the presence of sleep apnea is needed in order to help medical professionals make more informed decisions for their patients.

### Objective Statement:

The objective is to detect changes in the functional status of homebound patients with neurodegenerative disorders based on their movement around their home. In addition, this system will detect if the patient suffers from sleep apnea by collecting daily breathing patterns, with the use of algorithms to make inferences based on data, by the end of April 2023.

### Solutions:

**Movement detection:** ESP32 bluetooth transmitters to detect a wearable device on the target patient. When the device is in range, the system can initialize MLX90640 thermal cameras (unsure) and the central data collection system.

**Sleep detection:** A central data collection hub, powered by an ELEGOO UNO R3 board and several environmental sensors, will initialize to gather as much data as possible. The system collects data regularly when the patient is not detected but is always active when the patient is in range. Embedded machine learning models, using TinyML technology, on the microcontroller analyze the data and return results to a server.
 
<div align="center">

<img src="https://user-images.githubusercontent.com/113388793/212787252-fa01d1b9-34f5-4cf9-854a-c7954e988268.png" >

</div>


## Project Website

If you would like to find out more about the project, please checkout: [Project Website](https://www.google.com)

## Installing the libraries

This project uses several important libraries such as Pandas, NumPy, Matplotlib, and more. You can install them all by running the following commands with pip:

```bash 
pip install pandas
pip install numpy

python -m pip install -U matplotlib
pip install seaborn

pip install -U scikit-learn
pip install tensorflow

```

If you are not able to install the necessary libraries, I recommend you **use Jupyter Notebook with Anaconda**. I have a .ipynb file for the project as well.


## Dataset and configurations

Find all the project dataset files here: [INSERT RELEVANT FILES]

Feel free to use your own dataset files and configure them with: 

```python
# Configurations
```


## License

[MIT](https://choosealicense.com/licenses/mit/)
