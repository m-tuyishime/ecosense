#include <Arduino.h>
#include <Range.h>

#ifndef Sensor_H
#define Sensor_H

// enum for sensor state
struct StringArray2
{
   String arr[2];
};

// enum for sensor state
enum State
{
    TOO_LOW,
    TOO_HIGH,
    NORMAL
};

class Sensor
{
protected:
    byte pin; // analog pin
    String name; // sensor name
    String shortName; // sensor short name
    Range<int> minMaxRange; // min and max values
    Range<byte> critPercRange; // low and high critical percentage range
    Sensor(byte pin, String name, String shortName, Range<int> minMaxRange, Range<byte> critPercRange); // protected constructor (not to be used directly)
public:
    virtual String readSensor(); // read from sensor and return formatted value (% | °C) as string
    virtual State isCritical(); // check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
    StringArray2 getCritMessages(); // return 2 messages for LCD rows
};

#endif