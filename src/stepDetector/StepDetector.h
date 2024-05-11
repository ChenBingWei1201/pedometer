#ifndef STEP_DETECTOR_H
#define STEP_DETECTOR_H

#include <EEPROM.h>

class StepDetector {
public:
  StepDetector(float threshold, unsigned long debounceDelay, int bufferLength, int eepromAddress);
  ~StepDetector();
  void update(float x, float y, float z);
  int getStepCount();
  void saveStepCount();
  void loadStepCount();
  void resetStepCount();
  bool decrementStepCount(int count);

private:
  float calculateMagnitude(float x, float y, float z);
  void detectStep(float magnitude);

  float threshold;
  unsigned long debounceDelay;
  unsigned long lastStepTime;
  bool stepDetected;
  int stepCount;
  int bufferLength;
  float *buffer;
  int bufferIndex;
  int eepromAddress;
};

#endif
