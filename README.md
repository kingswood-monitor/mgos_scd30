# Mongoose OS Library: Inspirion SCD30 

## Overview

This is a library for the Inspirion SCD30 low power, high accuracy digital temperature, humidity, and CO2 sensor. It is a port to Mongoose OS of the Arduino SparkFun SCD30 driver - SparkFun's rights to the original code are acknowledged. It is tested on an ESP8266.

## Usage

### mos.yml

```
libs:
  - origin: https://github.com/richardjlyon/arduino_sparkfun_scd30

config_schema:
  - ["i2c.enable", true]
  - ["i2c.scl_gpio", "i", 5, { title: "scl" }]
  - ["i2c.sda_gpio", "i", 4, { title: "sda" }]
```

### main.cpp

```
#include "mgos_arduino_sparkfun_scd30.h"

// Create a sensor object
SCD30 *scd30 = mgos_SCD30_create();

enum mgos_app_init_result mgos_app_init(void)
{
  // Initialise the sensor
  mgos_SCD30_initialise(scd30);
  mgos_SCD30_set_measurement_interval(scd30, 3); // seconds
  mgos_SCD30_set_ambient_pressure(scd30, 1024);  // millibars
  ...
}

timer_cb(void *)
{
    double temp_c = mgos_SCD30_get_temperature(scd30);
    double humidity = mgos_SCD30_get_humidity(scd30);
    uint16_t co2 = mgos_SCD30_get_co2(scd30);
    ...◊
}
```