#include <Arduino.h>
#include <DHT_Mod.h>

#ifndef AirTempSensor_H
#define AirTempSensor_H

class AirTempSensor : public DHT_Mod
{
    public:
        AirTempSensor(byte pin, Range<byte> critPercRange); // constructor
        String readSensor(); // read from sensor and return formatted value (°C) as string
        State isCritical(); // check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
        StringArray2 getCritMessages(); // return 2 messages for LCD rows
};

#endif