#include "LightSensor.h"

// constructor
LightSensor::LightSensor(byte pin, Range<byte> critPercRange) : 
    Sensor(pin, "Light", "LIGHT", Range<int>(0, 1023), critPercRange){ // sets all properties values of the sensor
}
