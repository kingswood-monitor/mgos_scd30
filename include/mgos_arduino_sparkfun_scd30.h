/*
 * Arduido SparkFun_SCD30 Library API wrapper
 */

#include <stdint.h>
#include "sensor.h"

extern "C"
{
    // Create an SCD30 instance
    Sensor *mgos_SCD30_create(uint16_t seconds, uint16_t pressure_mbar);

    // Get temperature (centigrade)
    double mgos_SCD30_get_temperature(Sensor *sensor);

    // Get humidity (0.0-1.0)
    double mgos_SCD30_get_humidity(Sensor *sensor);

    // Get temperature (ppm)
    uint16_t mgos_SCD30_get_co2(Sensor *sensor);

    // // Begin measuring
    // bool mgos_SCD30_begin_measuring(Sensor *sensor);
}