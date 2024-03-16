#include "LightSensor.h"

LightSensor::LightSensor(uint8_t pin) : Sensor(pin, "Light") {
    this->minValue = 10;
    this->maxValue = 1010;
    this->lowCritPerc = 50;
    this->highCritPerc = 80;
}

