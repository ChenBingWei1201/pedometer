# pedometer for 2024 MakeNTU

## Credit
- [I made this Step Counter using ESP32!](https://youtu.be/T2tqk6CIBxY?feature=shared) by [THE ELECTRONIC GUY](https://youtube.com/@THEELECTRONICGUY?feature=shared)
- [ESP32 Step Tracker: Web-Integrated Counter Project](https://electronicblogs.com/esp32-step-tracker-web-integrated-counter-project/?fbclid=IwZXh0bgNhZW0CMTAAAR10UKi_eMHOYploklr9qOu50kAIZxe4UbqpVxCGjoUsV0_kMw_gDamnK9k_aem_AQmqz4e9_FJ34JsNXachKuukFWAZyuKCk6N65YAB-VNRh45kmFG0i_oGAHzd4Mr2E1Sgk92zvUInMnwh0xafVQHQ) February 8, 2024 by electronicblog296 
- [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit_ADXL345](https://github.com/adafruit/Adafruit_ADXL345)
- [EEPROM](https://docs.arduino.cc/learn/built-in-libraries/eeprom/)

## Introduction
This project is a pedometer that uses an ESP32 and an ADXL345 accelerometer to count the number of steps taken. The number of steps is displayed on an OLED display. If the power to ESP32 is corrupted, the number of steps remains.

## Hardware
- ESP32 
- ADXL345 accelerometer
- SSD1306 OLED display

## Software
- Arduino IDE
- Adafruit_SSD1306 library
- Adafruit_ADXL345 library
- EEPROM library

## How it works
The ESP32 reads the accelerometer data and counts the number of steps taken. The number of steps is displayed on the OLED display.

