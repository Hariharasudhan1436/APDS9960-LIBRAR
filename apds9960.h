#ifndef APDS9960_H
#define APDS9960_H

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#define APDS9960_I2C_ADDR 0x39

class APDS9960 {
public:
    APDS9960(i2c_inst_t* i2cPort);
    bool begin();
    uint8_t readProximity();
    bool gestureAvailable();
    uint8_t readGesture();

private:
    i2c_inst_t* i2c;
    bool writeByte(uint8_t reg, uint8_t data);
    bool readByte(uint8_t reg, uint8_t &data);
    bool enableGestureSensor();
};

#endif
