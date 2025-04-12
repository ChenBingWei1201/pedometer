# ESP32 Pedometer

A lightweight, battery-efficient step counter built with ESP32 and ADXL345 accelerometer. Created for 2024 MakeNTU hackathon.

![Pedometer Device](https://github.com/ChenBingWei1201/pedometer/assets/49435609/2b3c5fb0-52b2-4798-a085-2034e64963d5)

## ✨ Features

- **Accurate Step Counting**: Uses acceleration magnitude algorithm for reliable step detection
- **Persistent Memory**: Retains step count even when power is lost
- **Low Power Consumption**: Optimized for portable use
- **Touch Reset**: Easy step counter reset with ESP32's touch sensor
- **Real-time Display**: Instant step count feedback on OLED screen

## 🔧 Hardware Requirements

- ESP32 Microcontroller
- ADXL345 3-Axis Accelerometer
- SSD1306 OLED Display (128x64)
- Connecting wires
- Power source (battery or USB)

## 📦 Software Dependencies

- Arduino IDE
- Libraries:
  - Adafruit_SSD1306
  - Adafruit_ADXL345
  - Adafruit_GFX
  - Wire
  - EEPROM

## 🏗️ Project Structure

```
pedometer/
│
├── pedometer.ino              # Main program file
├── src/
│   ├── constant.h             # Constants and configuration
│   ├── oled/                  # OLED display module
│   │   ├── oled.h
│   │   └── oled.cpp
│   ├── adxl/                  # Accelerometer module
│   │   ├── adxl.h
│   │   └── adxl.cpp
│   └── stepDetector/          # Step detection algorithm
│       ├── StepDetector.h
│       └── StepDetector.cpp
```

## 🚀 How It Works

1. The ADXL345 accelerometer captures motion in three dimensions (X, Y, Z)
2. The StepDetector algorithm:
   - Calculates the magnitude of acceleration across all axes
   - Maintains a rolling buffer of recent values
   - Detects a step when movement exceeds average + threshold
   - Uses debounce logic to prevent false counts
3. Step count is displayed on the OLED screen and saved to EEPROM
4. Touch the T0 pin to reset the counter

## 📺 Demo

- [Step Count Demo](https://drive.google.com/file/d/1YQH5bl1licHwMoUTrAurOHJOOqHBxV4j/view?usp=drive_link)
- [Memory Persistence Demo](https://drive.google.com/file/d/1hPq_t__4g5AZ212mDPqRomSr6950t9aw/view?usp=drive_link)

## 🔄 Usage

1. Connect the hardware components according to the pins defined in the code
2. Upload the code to your ESP32
3. Power on the device
4. Start walking to see the step count increase
5. Touch the T0 pin to reset the counter when needed

## 📚 References

- [I made this Step Counter using ESP32!](https://youtu.be/T2tqk6CIBxY?feature=shared) by [THE ELECTRONIC GUY](https://youtube.com/@THEELECTRONICGUY?feature=shared)
- [ESP32 Step Tracker: Web-Integrated Counter Project](https://electronicblogs.com/esp32-step-tracker-web-integrated-counter-project/?fbclid=IwZXh0bgNhZW0CMTAAAR10UKi_eMHOYploklr9qOu50kAIZxe4UbqpVxCGjoUsV0_kMw_gDamnK9k_aem_AQmqz4e9_FJ34JsNXachKuukFWAZyuKCk6N65YAB-VNRh45kmFG0i_oGAHzd4Mr2E1Sgk92zvUInMnwh0xafVQHQ) February 8, 2024 by electronicblog296 
- [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit_ADXL345](https://github.com/adafruit/Adafruit_ADXL345)
- [EEPROM](https://docs.arduino.cc/learn/built-in-libraries/eeprom/)

## ⚠️ Disclaimer & License

This project is for educational purposes only. Not intended for commercial use.

This project is licensed under the [Creative Commons Attribution-NonCommercial 4.0 International License (CC BY-NC 4.0)](LICENSE). You are free to use, share, and adapt the material for non-commercial purposes, provided you give appropriate credit to the original authors.

---

⭐ If you find this project helpful, please give it a star! Your support motivates us to create better projects! (❁´◡`❁)