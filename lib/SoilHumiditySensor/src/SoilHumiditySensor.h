#include "Sensor.h"

#ifndef SoilHumiditySensor_H
#define SoilHumiditySensor_H

class SoilHumiditySensor : public Sensor
{
private:
public:
    SoilHumiditySensor(); // default constructor
    void init(byte pin, Range<byte> critPercRange); // initialize sensor
};


#endif