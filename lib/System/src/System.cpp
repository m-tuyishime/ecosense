#include "System.h"

// constructor
System::System(LCD* lcd, LightSensor* lightSensor, SoilHumiditySensor* soilHumiditySensor, AirHumiditySensor* airHumiditySensor, AirTempSensor* airTempSensor) {
    sensors[0] = lightSensor; // set the first sensor to the light sensor
    sensors[1] = soilHumiditySensor; // set the second sensor to the soil humidity sensor
    sensors[2] = airHumiditySensor; // set the third sensor to the air humidity sensor
    sensors[3] = airTempSensor; // set the fourth sensor to the air temperature sensor
    this->lcd = lcd; // set the lcd
}

// print the values of the sensors on the LCD in real time for 5 seconds
void System::printSensors() {
    for (int i = 0; i < 5; i++) { // loop for 5 times
        this->lcd->clear(); // clear the lcd
        String row1 = "LIGHT: " + this->sensors[0]->readSensor();
        row1 += " TEMP: " + this->sensors[3]->readSensor(); 
        String row2 = "SOIL_H: " + this->sensors[1]->readSensor();
        row2 += " AIR_H: " + this->sensors[2]->readSensor();
        this->lcd->print(row1, 0); // print the light and temperature to the first row
        this->lcd->print(row2, 1); // print the soil humidity to the second row
        delay(1000); // wait for a second
    }
}

// print the details of critical values on the LCD
void System::printDetails() {
    for (Sensor* sensor : this->sensors) { // loop through the sensors
        if (sensor->isCritical()) {
            for (int i = 0; i < 3; i++) { // loop for 3 seconds
            this->lcd->clear(); // clear the lcd
            StringArray2 messages = sensor->getCritMessages(); // get the critical messages
            this->lcd->print(messages.arr[0], 0); // print the first message on the first row
            this->lcd->print(messages.arr[1], 1); // print the second message on the second row
            delay(1000); // wait for a second
            }
        }
    }
}