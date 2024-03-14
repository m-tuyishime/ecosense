#include <Arduino.h>
#include "SoilHumiditySensor.h"

SoilHumiditySensor::SoilHumiditySensor(uint8_t pin) : Sensor(pin, "Soil Humidity") {
    this->minValue = 480; // air
    this->maxValue = 220; // water
    this->lowCritPerc = 60;
    this->highCritPerc = 80;
}