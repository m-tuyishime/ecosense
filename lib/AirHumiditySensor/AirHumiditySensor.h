#include <Arduino.h>
#include <DHT_Mod.h>

#ifndef AirHumiditySensor_H
#define AirHumiditySensor_H

class AirHumiditySensor : public DHT_Mod
{
    public:
        AirHumiditySensor(byte pin, Range<byte> critPercRange); // constructor
        String readSensor(); // read from sensor and return formatted value (%) as string
        State isCritical(); // check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
};

#endif