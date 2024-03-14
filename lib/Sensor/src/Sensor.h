#ifndef Sensor_H
#define Sensor_H

struct StringArray2
{
   String arr[2];
};

class Sensor
{
protected:
    uint8_t pin; // analog pin
    String name; // sensor name
    uint16_t minValue, maxValue; // min and max sensor values
    uint8_t lowCritPerc, highCritPerc; // low and high critical percentage values
    uint16_t analogRead(); // read from sensor
    uint16_t formatValue(uint16_t value); // format sensor value to account for min and max values
public:
    Sensor(uint8_t pin, String name);
    String readSensor(); // read from sensor and return formatted value (% | °C) as string
    int8_t isCritical(); // check if value is outside of lowCritPerc and highCritPerc range (1: low, 0: high, -1: normal)
    StringArray2 printCritical(); // return 2 messages for LCD rows
};

#endif