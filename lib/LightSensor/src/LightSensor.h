#include <Arduino.h>
#include "Sensor.h"

#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

class LightSensor : public Sensor
{
public:
    LightSensor(byte pin, Range<byte> critPercRange); // constructor
};



#endif
