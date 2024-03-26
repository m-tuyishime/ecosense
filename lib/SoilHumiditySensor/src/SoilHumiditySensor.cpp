#include <Arduino.h>
#include "SoilHumiditySensor.h"

// constructor
SoilHumiditySensor::SoilHumiditySensor(byte pin, Range<byte> critPercRange) : 
    Sensor(pin, "Soil Humidity", "SoilHum", Range<int>(200, 520), critPercRange) {} // sets all properties in Sensor parent class