#include "AirTempSensor.h"

// constructor
AirTempSensor::AirTempSensor(byte pin, Range<byte> critPercRange): 
    DHT_Mod(pin, "Air Temperature", "AIR_T", Range<int>(0, 50), critPercRange) {} // sets all properties in Sensor parent class


// read from sensor and return formatted value (°C) as string
String AirTempSensor::readSensor()
{
    delay(1000); // wait 2 seconds
    sensors_event_t event; // create event
    DHT_Mod::sensor->temperature().getEvent(&event); // get temperature event

    if (isnan(event.temperature)) { // if value is not a number
        Serial.println("Error reading temperature!"); // print error message
        return "Error"; // return error message
    } else {
        Serial.println(this->name + " value: " + String(event.temperature) + "°C"); // print value to serial monitor
        return String(event.temperature) + "°C"; // return value as string
    }
}

// check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
State AirTempSensor::isCritical()
{
    sensors_event_t event; // create event
    DHT_Mod::sensor->temperature().getEvent(&event); // get temperature event
    if (event.temperature < this->critPercRange.getMinValue()) // if value is below lowCritPerc
        return State::TOO_LOW;
    else if (event.temperature > this->critPercRange.getMaxValue()) // if value is above highCritPerc
        return State::TOO_HIGH;
    else
        return State::NORMAL;
}

// return 2 messages for LCD rows
StringArray2 AirTempSensor::getCritMessages()
{
    StringArray2 criticalValues; // create array of 2 strings
    criticalValues.arr[0] = this->shortName + ": " + this->readSensor(); // first message (ex. "Temp: 50°C")
    State status = this->isCritical(); // check if value is critical
    if (status == State::TOO_HIGH) // if value is below lowCritPerc
        criticalValues.arr[1] = "Reduce to "; // second message (ex. "Reduce to 20°C - 30°C")
    else
        criticalValues.arr[1] = "Increase to "; // second message (ex. "Increase to 20°C - 30°C")
    criticalValues.arr[1] += String(this->critPercRange.getMinValue()) + "°C - " + String(this->critPercRange.getMaxValue()) + "°C"; // add critical percentage range to second message
    return criticalValues;
}
