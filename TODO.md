# Homespace Data Acquisition - UML Capstone
This capstone project is for [UMass Chan Medical School](https://www.umassmed.edu/) where they tasked UML students to deliver a system capable of measuring a patient’s Homespace (the daily patterns of an individual’s movement in their home) and detecting the presence of sleep apnea (disorder causing one to suddenly wake up). Using the project description we have many key characteristics for our system:

 - Non-invasive and simple setup process
 - Datastreams are selective for the patient under observation
 - Scalable, leveraging existing data collection devices and open-source software
 - Little to no effort required from patient for system’s functionality


### Tasks left
- [ ] Data Collection #ml @ReDay 2023-01 
  - [ ] Collect data from Arduino
  - [ ] Verify data quality from SD card


- [ ] Machine Learning Model #ml @ReDay 2023-01
  - [ ] Build keyword spotting model template
  - [ ] Conduct explaratory data analysis on raw data
  - [ ] Preprocess data from Arduino
  - [ ] Train the model - Quantization Aware Training
  - [ ] Evaluate the model for performance 
  - [ ] Optimize the model further - Hyperparameter Optimization
  - [ ] Convert the model with TensorFlow Lite Micro converter
  - [ ] Deploy the model on Arduino board
  - [ ] Evaluate performance 
  - [ ] Optimize model to achieve 95% accuracy


- [ ] Homespace Website #web @ReDay 2023-01 - Edit this list
  - [ ] Decide website features and scope
  - [ ] Plan website structure
  - [ ] Start building front-end with React
  - [ ] Configure the server
  - [ ] Bundle the front-end and back-end
  - [ ] Integrate MongoDB to back-end
  - [ ] Connect MongoDb to front-end
  - [ ] Use Jest to test the website
  - [ ] Ensure Arduino is connected

### Completed tasks ✓
- [ ] Data Collection #ml @ReDay 2023-01 
  - [x] Arduino code for setting up sensors
  - [x] Arduino code for storing data in CSV file
  - [x] Store all code in one file
