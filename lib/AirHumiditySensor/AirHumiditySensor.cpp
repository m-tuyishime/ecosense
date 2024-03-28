#include "AirHumiditySensor.h"

// constructor
AirHumiditySensor::AirHumiditySensor(byte pin, Range<byte> critPercRange) : 
    DHT_Mod(pin, "Air Humidity", "AIR_H", Range<int>(0, 50), critPercRange) {} // sets all properties in Sensor parent class

// read from sensor and return formatted value (%) as string
String AirHumiditySensor::readSensor()
{
    delay(1000); // wait 2 seconds
    sensors_event_t event; // create event
    DHT_Mod::sensor->humidity().getEvent(&event); // get humidity event

    if (isnan(event.relative_humidity)) { // if value is not a number
        Serial.println("Error reading humidity!"); // print error message
        return "Error"; // return error message
    } else {
        Serial.println(this->name + " value: " + String(event.relative_humidity) + "%"); // print value to serial monitor
        return String(event.relative_humidity) + "%"; // return value as string
    }
}


// check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
State AirHumiditySensor::isCritical()
{
    sensors_event_t event; // create event
    DHT_Mod::sensor->humidity().getEvent(&event); // get humidity event
    if (event.relative_humidity < this->critPercRange.getMinValue()) { // if value is below lowCritPerc
        Serial.println(this->name + " value (" + String(event.relative_humidity) + "%) is too low!"); // print value to serial monitor
        return State::TOO_LOW;
    } else if (event.relative_humidity > this->critPercRange.getMaxValue()) { // if value is above highCritPerc
        Serial.println(this->name + " value (" + String(event.relative_humidity) + "%) is too high!"); // print value to serial monitor
        return State::TOO_HIGH;
    } else
        return State::NORMAL;
}
