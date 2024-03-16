#include <Arduino.h>
#include "LiquidCrystal_I2C.h"
#include "LightSensor.h"
#include "SoilHumiditySensor.h"
#include "TempSensor.h"

#ifndef LCD_H
#define LCD_H

class LCD
{
private:
    LiquidCrystal_I2C lcd; 
    LightSensor lightSensor;
    SoilHumiditySensor soilHumiditySensor;
    TempSensor tempSensor;
    void printLCD(String message, uint8_t row); // print the message on a specific row of the LCD
public:
    LCD(LightSensor lightSensor, SoilHumiditySensor soilHumiditySensor);
    LCD(LightSensor lightSensor, SoilHumiditySensor soilHumiditySensor, TempSensor tempSensor);
    void printSensors(int count); // print the values of the sensors on the LCD in real time for count + 1 seconds
    void printDetails(); // print the details of critical values on the LCD
};

#endif
