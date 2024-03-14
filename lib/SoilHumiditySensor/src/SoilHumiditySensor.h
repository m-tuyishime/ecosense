#include "Sensor.h"

#ifndef SoilHumiditySensor_H
#define SoilHumiditySensor_H

class SoilHumiditySensor : public Sensor
{
private:
public:
    SoilHumiditySensor(uint8_t pin);
};


#endif