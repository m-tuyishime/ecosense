#include "DHT_Mod.h"

DHT_Unified* DHT_Mod::sensor = nullptr;

DHT_Mod::DHT_Mod(byte pin, String name, String shortName, Range<int> minMaxRange, Range<byte> critPercRange) : 
    Sensor(pin, name, shortName, minMaxRange, critPercRange)// sets all properties in Sensor parent class
{
    if (DHT_Mod::sensor == nullptr) { // if sensor is not yet created
        DHT_Mod::sensor = new DHT_Unified(pin, DHT11); // create a new DHT sensor object as DHT11
        DHT_Mod::sensor->begin(); // start sensor
    }

    this->lastRead = 0; // set lastRead to 0
}
