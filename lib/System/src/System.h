#include <arduino.h>
#include <LCD.h>
#include <Sensor.h>
#include <LightSensor.h>
#include <SoilHumiditySensor.h>
#include <TempSensor.h>

#ifndef System_H
#define System_H

class System
{
private:
    Sensor sensors[4];

public:
    System(LightSensor lightSensor, SoilHumiditySensor soilHumiditySensor, TempSensor tempSensor);
    void printSensors(int count); // print the values of the sensors on the LCD in real time for count + 1 seconds
    void printDetails(); // print the details of critical values on the LCD
};

#endif
