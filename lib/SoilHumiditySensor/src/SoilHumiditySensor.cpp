#include <Arduino.h>
#include "SoilHumiditySensor.h"

SoilHumiditySensor::SoilHumiditySensor() : Sensor() // call base class constructor
{
}

void SoilHumiditySensor::init(byte pin, Range<byte> critPercRange)
{
    this->pin = pin; // set analog pin
    this->name = "Soil Humidity"; // set sensor name
    this->shortName = "SOIL_H"; // set sensor short name
    this->critPercRange = critPercRange; // set critical percentage range
    this->minMaxRange = Range<int>(200, 520); // set min and max values
}