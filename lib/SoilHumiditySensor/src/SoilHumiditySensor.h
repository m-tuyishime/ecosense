#include "Sensor.h"

#ifndef SoilHumiditySensor_H
#define SoilHumiditySensor_H

class SoilHumiditySensor : public Sensor
{
private:
public:
    SoilHumiditySensor(byte pin, Range<byte> critPercRange); // constructor
};


#endif