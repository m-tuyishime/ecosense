#include <arduino.h>
#include <LCD.h>
#include <Sensor.h>
#include <LightSensor.h>
#include <AirHumiditySensor.h>
#include <AirTempSensor.h>

#ifndef System_H
#define System_H

class System
{
private:
    Sensor* sensors[3];
    LCD* lcd;

public:
    System(LCD* lcd, LightSensor* lightSensor, AirHumiditySensor* airHumiditySensor, AirTempSensor* airTempSensor); // constructor
    void printSensors(); // print the values of the sensors on the LCD in real time for 5 seconds
    void printDetails(); // print the details of critical values on the LCD
};

#endif
