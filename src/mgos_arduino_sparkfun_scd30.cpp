
#include "mgos_arduino_sparkfun_scd30.h"
#include "SparkFun_SCD30_Arduino_Library.h"

class SCD30_Sensor : public Sensor
{
public:
    SCD30_Sensor(uint16_t seconds, uint16_t pressure_mbar)
    {
        sensor = SCD30();
        sensor.begin();
        sensor.setMeasurementInterval(seconds);
        sensor.setAmbientPressure(pressure_mbar);
    }

    float readTemperature()
    {
        return sensor.getTemperature();
    }

    float readHumidity()
    {
        return sensor.getHumidity();
    }

    int readCO2()
    {
        return sensor.getCO2();
    }

    bool isAvailable()
    {
        uint16_t deviceID = this->getDeviceId();
        uint16_t manufacturerID = this->getManufacturerId();

        return (deviceID == 0x1050) && (manufacturerID == 0x5449);
    }
    }

private:
    SCD30 sensor;
};

// Create an SCD30 instance
Sensor *mgos_SCD30_create(uint16_t seconds, uint16_t pressure_mbar)
{
    return new SCD30_Sensor(seconds, pressure_mbar);
}

// Get temperature (centigrade)
double mgos_SCD30_get_temperature(Sensor *sensor)
{
    if (sensor == nullptr)
        return -1;
    return sensor->readTemperature();
}

// Get humidity (0.0-1.0)
double mgos_SCD30_get_humidity(Sensor *sensor)
{
    if (sensor == nullptr)
        return -1;
    return sensor->readHumidity();
}

// Get CO2 (ppm)
uint16_t mgos_SCD30_get_co2(Sensor *sensor)
{
    if (sensor == nullptr)
        return -1;
    return sensor->readCO2();
}