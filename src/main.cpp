/***********************************************************************************/
// Program header

// Project: 	Arduino - Environment Monitor
// Authors:		Muhoza Olivier Tuyishime, Tagne Nzeuguem Igor Laurel
/***********************************************************************************/
// Hardware definitions

// Arduino Uno R3
// DHT22                            - on A3
// KY-018 photoresistor             - on A0
// LCD 16X2 I2C                     - on SDA, SCL
/***********************************************************************************/
// Libraries

#include <LCD.h>
#include <LightSensor.h>
#include <AirTempSensor.h>
#include <AirHumiditySensor.h>

#include <System.h>

/***********************************************************************************/
// Constant definitions

#define LIGHT_C 0
#define SOIL_C 5
#define DHT_C 2
/***********************************************************************************/
// Global variables

LightSensor* lightSensor; // light sensor
AirTempSensor* airTempSensor; // air temperature sensor
AirHumiditySensor* airHumiditySensor; // air humidity sensor

LCD* lcd; // LCD object
System* arduino; // system object
/***********************************************************************************/
// Setup

void setup() {
    Serial.begin(9600); // start serial communication
    lcd = new LCD(); // initialize LCD
    airTempSensor = new AirTempSensor(DHT_C, Range<byte>(20, 30)); // initialize air temperature sensor with critical temperature value range of 20-30°C
    airHumiditySensor = new AirHumiditySensor(DHT_C, Range<byte>(20, 80)); // initialize air humidity sensor with critical value percentage range of 20-80% 
    lightSensor = new LightSensor(LIGHT_C, Range<byte>(50, 100)); // initialize light sensor with critical value percentage range of 50-100%

    arduino = new System(lcd, lightSensor, airHumiditySensor, airTempSensor); // initialize system object
}
/***********************************************************************************/
// Loop

void loop() {
    // airTempSensor->readSensor(); // read from air temperature sensor
    // airHumiditySensor->readSensor(); // read from air humidity sensor
    // lightSensor->readSensor(); // read from light sensor
    // delay(1000); // wait for a second
    arduino->printSensors(); // print sensor values on LCD
    arduino->printDetails(); // print critical values on LCD
}
/***********************************************************************************/
