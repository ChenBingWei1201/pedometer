#ifndef ADXL_H
#define ADXL_H

#include <Adafruit_ADXL345_U.h>
#include <Adafruit_Sensor.h>

class ADXL {
public:
  ADXL();
  void init();
  bool readAcceleration(float &x, float &y, float &z);

private:
  Adafruit_ADXL345_Unified accel;
};

#endif
