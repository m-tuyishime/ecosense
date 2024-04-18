#include "SoilHumiditySensor.h"

// constructor
SoilHumiditySensor::SoilHumiditySensor(byte pin, Range<byte> critPercRange) : 
    Sensor(pin, "Soil Humidity", "SOIL_HUMIDITY", Range<int>(200, 500), critPercRange){ // sets all properties values of the sensor
}