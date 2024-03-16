/***********************************************************************************/
// Program header

// Project: 	Arduino - Environment Monitor
// Authors:		Muhoza Olivier Tuyishime, Tagne Nzeuguem Igor Laurel
/***********************************************************************************/
// Hardware definitions

// Arduino Uno R3
// DHT22                            - on A3
// Capacitive soil moisture sensor  - on A5
// KY-018 photoresistor             - on A0
// LCD 16X2 I2C                     - on SDA, SCL
/***********************************************************************************/
// Libraries

#include <LCD.h>
#include <LightSensor.h>
#include <SoilHumiditySensor.h>
// #include "libs/TempSensor.h"

/***********************************************************************************/
// Constant definitions

#define LIGHT_C 0
#define SOIL_C 5
#define DHT_C 3
/***********************************************************************************/
// Global variables

LightSensor lightSensor(0); // light sensor
SoilHumiditySensor soilHumiditySensor(5); // soil humidity sensor
// TempSensor tempSensor(DHT_C); // temperature sensor ///////////////////////////////////////////////////////////////////////////////////////////
LCD lcd(lightSensor, soilHumiditySensor); // LCD 16X2 I2C
/***********************************************************************************/
// Setup

void setup() {
   Serial.begin(9600); // start serial communication
}
/***********************************************************************************/
// Loop

void loop() {
    lcd.printSensors(5-1); // print the sensors values for 5 seconds
    lcd.printDetails(); // print the details of any critical values
}
/***********************************************************************************/
