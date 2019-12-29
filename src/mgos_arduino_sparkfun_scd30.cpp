
#include "mgos_arduino_sparkfun_scd30.h"

// Create an SCD30 instance
SCD30 *mgos_SCD30_create()
{
    return new SCD30();
}

// Initialise the sensor
bool mgos_SCD30_initialise(SCD30 *scd)
{
    if (scd == nullptr)
        return false;
    bool ok = scd->begin();
    return ok;
}

// Set Measurement Interval (seconds)
void mgos_SCD30_set_measurement_interval(SCD30 *scd, uint16_t seconds)
{
    if (scd == nullptr)
        return;
    scd->setMeasurementInterval(seconds);
}

// Set ambient pressure (millibars)
void mgos_SCD30_set_ambient_pressure(SCD30 *scd, uint16_t pressure_mbar)
{
    if (scd == nullptr)
        return;
    scd->setAmbientPressure(pressure_mbar);
}

// Get temperature (centigrade)
double mgos_SCD30_get_temperature(SCD30 *scd)
{
    if (scd == nullptr)
        return -1;
    return scd->getTemperature();
}

// Get humidity (0.0-1.0)
double mgos_SCD30_get_humidity(SCD30 *scd)
{
    if (scd == nullptr)
        return -1;
    return scd->getHumidity();
}

// Get CO2 (ppm)
uint16_t mgos_SCD30_get_co2(SCD30 *scd)
{
    if (scd == nullptr)
        return -1;
    return scd->getCO2();
}