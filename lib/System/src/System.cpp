#include "System.h"

// constructor
System::System(LCD* lcd, LightSensor* lightSensor, AirHumiditySensor* airHumiditySensor, AirTempSensor* airTempSensor) {
    sensors[0] = lightSensor; // set the first sensor to the light sensor
    sensors[1] = airHumiditySensor; // set the second sensor to the air humidity sensor
    sensors[2] = airTempSensor; // set the third sensor to the air temperature sensor
    this->lcd = lcd; // set the lcd
}

// print the values of the sensors on the LCD in real time for 5 seconds
void System::printSensors() {
    this->lcd->clear(); // clear the LCD
    for (int i = 0; i < 5; i++) { // loop for 5 times
        String row1 = "LT:" + this->sensors[0]->readSensor(); // get the light value
        row1 += " TMP:" + this->sensors[2]->readSensor(); // get the temperature value
        String row2 = "HUMIDITY: " + this->sensors[1]->readSensor(); // get the soil humidity value
        this->lcd->print(row1, 0); // print the light and temperature to the first row
        this->lcd->print(row2, 1); // print the soil humidity to the second row
        delay(1000); // wait for a second
    }
}

// print the details of critical values on the LCD
void System::printDetails() {
    for (Sensor* sensor : this->sensors) { // loop through the sensors
        if (sensor->isCritical() == State::TOO_HIGH || sensor->isCritical() == State::TOO_LOW) { // if the sensor value is too high or too low
            this->lcd->clear(); // clear the LCD
            for (int i = 0; i < 3; i++) { // loop for 3 times
                StringArray2 messages = sensor->getCritMessages(); // get the critical messages
                this->lcd->print(messages.arr[0], 0); // print the first message on the first row
                this->lcd->print(messages.arr[1], 1); // print the second message on the second row
                delay(1000); // wait for a second
            }
        }
    }
}