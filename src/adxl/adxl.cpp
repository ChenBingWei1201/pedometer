#include "adxl.h"

ADXL::ADXL() : accel(12345) {}

void ADXL::init() {
  if (!accel.begin()) {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    while (1)
      ;
  }
  accel.setRange(ADXL345_RANGE_16_G);
}

bool ADXL::readAcceleration(float &x, float &y, float &z) {
  sensors_event_t event;
  accel.getEvent(&event);
  x = event.acceleration.x;
  y = event.acceleration.y;
  z = event.acceleration.z;
  return true;
}
