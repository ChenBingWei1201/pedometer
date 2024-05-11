#include "StepDetector.h"
#include "../constant.h"
#include <Arduino.h>
#include <math.h>

StepDetector::StepDetector(float threshold, unsigned long debounceDelay, int bufferLength, int eepromAddress)
    : threshold(threshold), debounceDelay(debounceDelay),
      bufferLength(bufferLength), eepromAddress(eepromAddress), stepCount(0),
      stepDetected(false), lastStepTime(0), bufferIndex(0) {
  buffer = new float[bufferLength]();
  EEPROM.begin(EEPROM_SIZE);
}

StepDetector::~StepDetector() {
  delete[] buffer;
}

void StepDetector::update(float x, float y, float z) {
  float magnitude = calculateMagnitude(x, y, z);
  buffer[bufferIndex] = magnitude;
  bufferIndex = (bufferIndex + 1) % bufferLength;
  detectStep(magnitude);
}

float StepDetector::calculateMagnitude(float x, float y, float z) {
  return sqrt(x * x + y * y + z * z);
}

void StepDetector::detectStep(float magnitude) {
  float avgMagnitude = 0;
  for (int i = 0; i < bufferLength; i++) {
    avgMagnitude += buffer[i];
  }
  avgMagnitude /= bufferLength;

  unsigned long currentMillis = millis();

  if (magnitude > (avgMagnitude + threshold)) {
    if (!stepDetected && (currentMillis - lastStepTime) > debounceDelay) {
      this->stepCount++;
      stepDetected = true;
      lastStepTime = currentMillis;
    }
  } else {
    stepDetected = false;
  }
}

int StepDetector::getStepCount() { 
  return this->stepCount;
}

void StepDetector::saveStepCount() {
  EEPROM.write(0, this->stepCount);
  EEPROM.commit();
}

void StepDetector::loadStepCount() {
  this->stepCount = EEPROM.readInt(0);
}

void StepDetector::resetStepCount() {
  this->stepCount = 0;
}

bool StepDetector::decrementStepCount(int count) {
  if (this->stepCount < count) {
    return false;
  }
  this->stepCount -= count;
  return true;
}