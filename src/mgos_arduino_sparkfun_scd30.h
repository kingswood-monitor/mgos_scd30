/*
 * Arduido SparkFun_SCD30 Library API wrapper
 */

#include "SparkFun_SCD30_Arduino_Library.h"

#ifdef __cplusplus
extern "C"
{
#endif

    // Create an SCD30 instance
    SCD30 *mgos_SCD30_create();

    // Initialise the sensor
    bool mgos_SCD30_initialise(SCD30 *scd);

    // Set Measurement Interval (seconds)
    void mgos_SCD30_set_measurement_interval(SCD30 *scd, uint16_t seconds);

    // Set ambient pressure (millibars)
    void mgos_SCD30_set_ambient_pressure(SCD30 *scd, uint16_t pressure_mbar);

    // Get temperature (centigrade)
    double mgos_SCD30_get_temperature(SCD30 *scd);

    // Get humidity (0.0-1.0)
    double mgos_SCD30_get_humidity(SCD30 *scd);

    // Get temperature (ppm)
    uint16_t mgos_SCD30_get_co2(SCD30 *scd);

#ifdef __cplusplus
}
#endif /* __cplusplus */