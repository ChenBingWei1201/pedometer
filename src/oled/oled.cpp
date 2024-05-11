#include "oled.h"

OLED::OLED(int width, int height, int reset_pin): display(width, height, &Wire, reset_pin) {}

void OLED::init() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void OLED::updateOledDisplay(const String &text, int size, int stepCount) {
  display.clearDisplay();
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(text);
  display.print(stepCount);
  display.display();
}
