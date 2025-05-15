# APDS9960-LIBRARY
# APDS9960 C++ Library for Raspberry Pi Pico

This project demonstrates how to interface the APDS9960 proximity and gesture sensor with Raspberry Pi Pico using I2C and C++ (Pico SDK).

## Features
- I2C Communication (0x39)
- Read proximity values (0–255)
- Basic gesture detection support
- Modular reusable C++ library

## Pin Connections

| APDS9960 | Pico Pin |
|----------|----------|
| VCC      | 3.3V     |
| GND      | GND      |
| SDA      | GPIO 0   |
| SCL      | GPIO 1   |

## Output Example
APDS9960 Initialized.
Proximity: 5
Proximity: 27
Proximity: 41


## Build Instructions
```bash
mkdir build
cd build
cmake ..
make

Upload the .uf2 to your Pico and open the serial monitor at 115200 baud.

yaml
Copy
Edit

---

Would you like me to zip all this into a folder or help you publish it to GitHub directly?
