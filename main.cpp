#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "apds9960.h"

#define I2C_PORT i2c0
#define SDA_PIN 0
#define SCL_PIN 1

int main() {
    stdio_init_all();

    i2c_init(I2C_PORT, 100000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    APDS9960 sensor(I2C_PORT);
    if (!sensor.begin()) {
        printf("APDS9960 not found.\n");
        return 1;
    }

    printf("APDS9960 Initialized.\n");

    while (true) {
        uint8_t prox = sensor.readProximity();
        printf("Proximity: %d\n", prox);
        sleep_ms(500);
    }
}
