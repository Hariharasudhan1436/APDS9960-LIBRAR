#include "apds9960.h"

#define ENABLE       0x80
#define GESTURE_ENABLE 0xAB
#define GSTATUS      0xAF
#define GFIFO_U      0xFC
#define GFLVL        0xAE
#define GCONF4       0xAB
#define ID           0x92
#define APDS9960_ID  0xAB

APDS9960::APDS9960(i2c_inst_t* i2cPort) {
    i2c = i2cPort;
}

bool APDS9960::writeByte(uint8_t reg, uint8_t data) {
    uint8_t buffer[2] = { reg, data };
    return i2c_write_blocking(i2c, APDS9960_I2C_ADDR, buffer, 2, false) == 2;
}

bool APDS9960::readByte(uint8_t reg, uint8_t &data) {
    if (i2c_write_blocking(i2c, APDS9960_I2C_ADDR, &reg, 1, true) != 1) return false;
    return i2c_read_blocking(i2c, APDS9960_I2C_ADDR, &data, 1, false) == 1;
}

bool APDS9960::begin() {
    uint8_t id;
    if (!readByte(ID, id)) return false;
    if (id != APDS9960_ID) return false;

    writeByte(ENABLE, 0x41); // Power ON + Proximity Enable
    return enableGestureSensor();
}

bool APDS9960::enableGestureSensor() {
    writeByte(GCONF4, 0x01); // Enable Gesture
    return true;
}

uint8_t APDS9960::readProximity() {
    uint8_t prox;
    if (!readByte(0x9C, prox)) return 0;
    return prox;
}

bool APDS9960::gestureAvailable() {
    uint8_t gstatus;
    readByte(GSTATUS, gstatus);
    return (gstatus & 0x01);
}

uint8_t APDS9960::readGesture() {
    uint8_t fifo_level, up;
    readByte(GFLVL, fifo_level);
    if (fifo_level == 0) return 0;

    readByte(GFIFO_U, up);
    return up;
}
