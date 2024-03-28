#include <Arduino.h>
#include "Sensor.h"

#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

class LightSensor : public Sensor
{
private:
    byte daylightSecs[10800]; // creates an array of 10800 bytes, or 86400 bits to represent each second of the day
    unsigned long currentSec; // current second of the day
    unsigned long lastMillis; // last millisecond
    byte lightThreshPerc; // light threshold percentage
    bool checkQuota; // if critical percentage range should be checked
    void incSec(); // increment current second and set value in daylightSecs array
    byte getDaylightSec(unsigned long sec); // get light value for a specific second
    void setDaylightSec(unsigned long sec, byte light); // set light value for a specific second
public:
    LightSensor(byte pin, Range<byte> critPercRange, byte lightThreshPerc); // constructor
    String readSensor(); // read from sensor and return formatted value (%) as string
    State isCritical(); // check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
    StringArray2 getCritMessages(); // return 2 messages for LCD rows
};



#endif
