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
// #include <LightSensor.h>
#include <SoilHumiditySensor.h>
// #include "libs/TempSensor.h"

/***********************************************************************************/
// Constant definitions

#define LIGHT_C 0
#define SOIL_C 5
#define DHT_C 3
/***********************************************************************************/
// Global variables

// LightSensor lightSensor(0); // light sensor
SoilHumiditySensor soilHumiditySensor; // soil humidity sensor
// // TempSensor tempSensor(DHT_C); // temperature sensor ///////////////////////////////////////////////////////////////////////////////////////////
LCD lcd; // LCD object
/***********************************************************************************/
// Setup

void setup() {
    Serial.begin(9600); // start serial communication
    // lcd.init(); // initialize the LCD
    // lcd.print("Hello World!", 0); // print the message on the first row
    soilHumiditySensor.init(SOIL_C, Range<byte>(20, 80)); // initialize soil humidity sensor
}
/***********************************************************************************/
// Loop

void loop() {
    soilHumiditySensor.readSensor(); // read from soil humidity sensor
    delay(1000); // wait for 1 second
}
/***********************************************************************************/
