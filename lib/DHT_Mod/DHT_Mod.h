#include <Arduino.h>
#include <Sensor.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#ifndef DHT_Mod_h
#define DHT_Mod_h

class DHT_Mod : public Sensor
{
    protected:
        static DHT_Unified* sensor;
        short lastRead;
        DHT_Mod(byte pin, String name, String shortName, Range<int> minMaxRange, Range<byte> critPercRange); // protected constructor (not to be used directly)        
};

#endif

