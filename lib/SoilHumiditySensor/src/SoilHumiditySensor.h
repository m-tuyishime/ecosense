#include <Arduino.h>
#include "Sensor.h"

#ifndef SOILHUMIDITYSENSOR_H
#define SOILHUMIDITYSENSOR_H

class SoilHumiditySensor : public Sensor
{
public:
    SoilHumiditySensor(byte pin, Range<byte> critPercRange); // constructor
};

#endif