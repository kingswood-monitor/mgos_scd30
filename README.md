# Mongoose OS Library: Inspirion SCD30 

## Overview

This is a library for the Inspirion SCD30 low power, high accuracy digital temperature, humidity, and CO2 sensor. It is a port to Mongoose OS of the Arduino SparkFun SCD30 driver - SparkFun's rights to the original code are acknowledged. It is tested on an ESP8266.

Interaction with the device is via a virtual interface. See [Mongoose OS Library: Sensor virtual interface](https://github.com/richardjlyon/arduino_sensor_interface) for details.

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
Sensor *sensor;

enum mgos_app_init_result mgos_app_init(void)
{
  // Initialise the sensor
  sensor = mgos_HDC1080_create();
  ...
}

timer_cb(void *)
{
    double temp_c = sensor->readTemperature();
    double humidity = sensor->readHumidity();
    int co2 = sensor->readCO2();
    ...◊
}
```