#ifndef OLED_H
#define OLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class OLED {
public:
  OLED(int width, int height, int reset_pin);
  void init();
  void updateOledDisplay(const String &text, int size, int stepCount);

private:
  Adafruit_SSD1306 display;
};

#endif
