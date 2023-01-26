# Homespace Data Acquisition - UML Capstone

## Overview

Welcome to my UML capstone project, where I delve into the intersection of machine learning, hardware, and web development to create a custom home system for monitoring and improving the health of individuals suffering from sleep apnea. The project aims to develop a home system that can gather data from various sensors installed in a custom device and use that data to understand a patient's daily movement patterns and the presence of sleep apnea. This technology improves the patient's lifestyle by providing them with more accurate and personalized treatment plans, and healthcare professionals with more detailed information about the patient's condition. Through this project, I aim to demonstrate the potential of IoT and TinyML in healthcare and how it influences people's lives. I will be using a combination of hardware and software to create a custom system that can gather data from multiple sources and use that data to build machine-learning models to detect sleep apnea.

### Problem Statement:

There is a lack of objective and quantitative data with regard to homebound patients’ well-being, which results in many patients receiving inadequate support based on their needs. A system that establishes and tracks patterns in a patient’s movement in their home and detects the presence of sleep apnea is needed in order to help medical professionals make more informed decisions for their patients.

### Objective Statement:

The objective is to detect changes in the functional status of homebound patients with neurodegenerative disorders based on their movement around their homes. In addition, this system will detect if the patient suffers from sleep apnea by collecting daily breathing patterns, with the use of algorithms to make inferences based on data, by the end of April 2023.

### Solutions:

**Movement detection:** ESP32 Bluetooth transmitters detect a wearable device on the target patient. When the device is in range, the system can initialize MLX90640 thermal cameras (unsure) and the central data collection system.


<div align="center" padding-bottom: 100px>

<img src="https://user-images.githubusercontent.com/113388793/214855503-8ecb8aa5-cfe0-4c4e-80c0-b68d7904b775.PNG">

</div>


<div align = 'center'>

Flowchart for movement detection

</div>

**Sleep detection:** A central data collection hub, powered by an ELEGOO UNO R3 board and several environmental sensors, will initialize to gather as much data as possible. The system collects data regularly when the patient is not detected but is always active when the patient is in range. Embedded machine learning models, using TinyML technology, on the microcontroller analyze the data and return results to a server.
 
<div align="center">

<img src="https://user-images.githubusercontent.com/113388793/214855097-9de0dd4e-f75c-4cd2-baac-8225e80b091e.PNG" >

</div>

<div align = 'center'>

Flowchart for sleep apnea detection

</div>



## Project Website

If you would like to find out more about the project, please checkout: [Homespace Project](https://www.redaysblog.com/projects/uml-capstone)

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
