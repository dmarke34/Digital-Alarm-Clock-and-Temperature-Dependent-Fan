# I²C-Based Temperature, Time, and Alarm Monitoring System

## 📌 Overview
This project implements a **real-time embedded monitoring system** on the **PIC18F4620 microcontroller**. The system integrates multiple peripherals to monitor **time, temperature, RPM, voltage, heater state, and alarms**, while providing **visual, audible, and user-input feedback** via a TFT display, RGB LEDs, buzzer, and IR remote.

The firmware is written in **Embedded C**, emphasizing **interrupt-driven design**, **deterministic timing**, and **low-level peripheral control**.

---

## ⚙️ Hardware Components
- **Microcontroller:** PIC18F4620  
- **RTC:** DS3231 (I²C)
- **Temperature Sensor:** DS1621 (I²C)
- **Display:** ST7735 TFT
- **User Input:** IR Remote (NEC protocol), external push-button
- **Output Devices:**  
  - RGB LED (status + alarm indication)  
  - Buzzer (audible alerts)  
  - Heater & fan control (PWM)  
- **Sensors:** Voltage monitoring (ADC), RPM measurement

---

## 🧠 System Features
- Real-time clock and calendar display
- Temperature measurement (°C and °F)
- Heater control with configurable temperature setpoint
- Alarm functionality with buzzer and RGB LED animation
- RPM measurement and visualization
- IR remote control for configuration
- Interrupt-driven push-button handling
- Serial debug output via UART

---

## 🔄 Program Flow

### Initialization
- Configure oscillator and system clock
- Initialize UART for debugging output
- Configure GPIO directions
- Initialize ADC for voltage sensing
- Initialize I²C bus (100 kHz)
- Initialize DS3231 RTC and DS1621 temperature sensor
- Initialize TFT display
- Configure interrupts and timers
- Set default heater temperature

### Main Loop
- Read current time from **DS3231** once per second
- Read temperature from **DS1621**
- Convert temperature to Fahrenheit
- Measure RPM and system voltage
- Update RGB LED based on RPM
- Monitor heater operation
- Check and handle alarm conditions
- Update TFT display with real-time data
- Process IR remote input
- Handle external push-button interrupts

---

## ⏰ Alarm Operation
- Alarm enable/disable controlled via push-button
- When alarm time matches RTC:
  - Activate buzzer (4 kHz)
  - Cycle RGB LED colors
- Alarm clears automatically when voltage threshold is exceeded
- Alarm state and matching logic handled in `Test_Alarm()`

---

## 🎮 IR Remote Controls
| Button | Function |
|------|---------|
| Channel – | Set system time |
| Channel | Set alarm time |
| Channel + | Set heater temperature |
| Play/Pause | Toggle heater ON/OFF |
| Invalid input | Error beep |

---

## 🖥️ Serial Debug Output
System status is printed over UART, including:
- Time and date
- Temperature (°C / °F)
- Alarm and heater state
- RPM and PWM duty cycle

Example:
12:30:05 11/15/21 Temp = 25 C = 77 F alarm = 1 Heater = 0 RPM = 1450 dc = 50

---

## 🧩 Software Architecture
- **Low-level drivers:** I²C, ADC, UART, PWM
- **Interrupt handlers:** External interrupts, timers
- **Application logic:** Heater control, alarm logic, RPM processing
- **Display driver:** ST7735 graphics rendering
- **Utilities:** Voltage reading, buzzer control, RGB LED control

---

## 📂 Key Source Files
- `main.c` – System initialization and main control loop
- `I2C.c / I2C_Support.c` – I²C communication
- `Interrupt.c` – Interrupt handling
- `Fan_Support.c` – Heater and fan PWM control
- `ST7735_TFT.c` – Display driver
- `utils.c` – Helper functions (voltage, RPM, buzzer)

---

## 📚 Learning Outcomes
This project demonstrates:
- Real-time embedded system design
- Interrupt-driven firmware architecture
- Multi-peripheral integration (**I²C, UART, ADC, PWM**)
- Hardware abstraction and driver development
- Deterministic control loops
- Embedded debugging and validation
- Sensor data acquisition and visualization

---

## 🚀 Future Enhancements
- Add non-volatile logging for temperature and events
- Implement low-power sleep modes
- Add menu-based UI navigation
- Improve alarm scheduling options
- Add battery backup monitoring

---

## 📄 License
Educational use only  
Developed for **ECE3301L – Embedded Systems Lab**

---

## 👥 Authors
Developed as part of an embedded systems curriculum.  
Maintained for instructional and portfolio use.
