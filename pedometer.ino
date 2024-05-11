#include "src/oled/oled.h"
#include "src/adxl/adxl.h"
#include "src/stepDetector/StepDetector.h"
#include "src/constant.h"

OLED *display;
ADXL *accelerometer;
StepDetector *stepDetector;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  display = new OLED(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET);
  display->init();
  accelerometer = new ADXL();
  accelerometer->init();
  stepDetector = new StepDetector(THRESHOLD, DEBOUNCE_DELAY, BUFFER_LENGTH, 0);
  stepDetector->loadStepCount();
}

void loop() {
  float x, y, z;
  if (accelerometer->readAcceleration(x, y, z)) {
    stepDetector->update(x, y, z);
    display->updateOledDisplay("Step Count: ", 2, stepDetector->getStepCount());
    if (touchRead(T0) < 40) {
      stepDetector->resetStepCount();
    }
    stepDetector->saveStepCount();
  }
}
