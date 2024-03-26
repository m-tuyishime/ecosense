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
#include <AirTempSensor.h>

/***********************************************************************************/
// Constant definitions

#define LIGHT_C 0
#define SOIL_C 5
#define TEMP_C 2
/***********************************************************************************/
// Global variables

// LightSensor lightSensor(0); // light sensor
SoilHumiditySensor* soilHumiditySensor; // soil humidity sensor
AirTempSensor* airTempSensor; // air temperature sensor

LCD* lcd; // LCD object
/***********************************************************************************/
// Setup

void setup() {
    Serial.begin(9600); // start serial communication
    // lcd = new LCD(); // initialize LCD
    // lcd->print("Hello World!", 0); // print the message on the first row
    // soilHumiditySensor = new SoilHumiditySensor(SOIL_C, Range<byte>(20, 80)); // initialize soil humidity sensor with critical percentage range
    airTempSensor = new AirTempSensor(TEMP_C, Range<byte>(20, 30)); // initialize air temperature sensor with critical percentage range
}
/***********************************************************************************/
// Loop

void loop() {
    // soilHumiditySensor->readSensor(); // read from soil humidity sensor
    airTempSensor->readSensor(); // read from air temperature sensor
    delay(1000); // wait for 1 second
}
/***********************************************************************************/
