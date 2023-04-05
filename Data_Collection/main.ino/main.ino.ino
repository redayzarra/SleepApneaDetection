#include <Arduino.h>
#include <PDM.h>
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_error_reporter.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include <tensorflow/lite/version.h>
#include "audio_processing.h"
#include "keyword_actions.h"
#include "Marvin1_model.cc"

// This the main file which contains the setup() and loop() functions, as well as any other high-level logic specific to the Arduino Nano 33 BLE. 
// I will also include necessary libraries and other files in this main sketch.

// SETUP - constants, variables, and the TensorFlow Lite interpreter
constexpr int kModelTensorArenaSize = 2 * 1024;
uint8_t model_tensor_arena[kModelTensorArenaSize];

static tflite::MicroErrorReporter micro_error_reporter;
tflite::ErrorReporter* error_reporter = &micro_error_reporter;
static tflite::AllOpsResolver resolver;

const tflite::Model* model = nullptr;
static tflite::MicroInterpreter static_interpreter(model, resolver, model_tensor_arena, kModelTensorArenaSize, error_reporter);
tflite::MicroInterpreter* interpreter = nullptr;

TfLiteTensor* model_input = nullptr;
TfLiteTensor* model_output = nullptr;

// VARIABLES
const char* keywords[] = {"Background noise", "Hello Marvin", "Goodnight Marvin"};
const int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  PDM.begin(1, 16000);
  PDM.setGain(20);
  PDM.onReceive(onPDMdata);

  setup_audio_processing();
  setup_tf_lite_interpreter();
}

void loop() {
  loop_audio_processing();
  loop_tf_lite_interpreter();
}