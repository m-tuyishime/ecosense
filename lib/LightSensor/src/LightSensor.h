#include <Arduino.h>
#include "Sensor.h"

#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

class LightSensor : public Sensor
{
private:
public:
    LightSensor(uint8_t pin);
};



#endif
