#include "Sensor.h"

// constructor
Sensor::Sensor() : minMaxRange(0, 0), critPercRange(0, 0) {} // constructor with default values (0, 0, 0, 0)

// initialize sensor
void Sensor::init(byte pin, String name, String shortName, Range<int> minMaxRange, Range<byte> critPercRange)
{
    this->pin = pin; // set analog pin
    this->name = name; // set sensor name
    this->shortName = shortName; // set sensor short name
    this->critPercRange = critPercRange; // set critical percentage range
    this->minMaxRange = minMaxRange; // set min and max values
}

// return 2 messages for LCD rows
StringArray2 Sensor::getCritMessages() {
    StringArray2 criticalValues; // create array of 2 strings
    criticalValues.arr[0] = this->name + ": " + this->readSensor(); // first message (ex. "Light: 50%")
    State status = this->isCritical(); // check if value is critical
    if (status == State::TOO_HIGH) // if value is below lowCritPerc
        criticalValues.arr[1] = "Reduce to "; // second message (ex. "Reduce to 50% - 80%")
    else
        criticalValues.arr[1] = "Increase to "; // second message (ex. "Increase to 50% - 80%")
    criticalValues.arr[1] += String(this->critPercRange.getMinValue()) + "% - " + String(this->critPercRange.getMaxValue()) + "%"; // add critical percentage range to second message
    return criticalValues;
}


// check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
State Sensor::isCritical() {
    int value = analogRead(this->pin); // read from sensor
    value = this->minMaxRange.formatValue(this->name, value); // format value to account for min and max values
    if (map(value, this->minMaxRange.getMinValue(), this->minMaxRange.getMaxValue(), 0, 100) < this->critPercRange.getMinValue()) // if value is below lowCritPerc
        return State::TOO_LOW;
    else if (map(value, this->minMaxRange.getMinValue(), this->minMaxRange.getMaxValue(), 0, 100) > this->critPercRange.getMaxValue()) // if value is above highCritPerc
        return State::TOO_HIGH;
    else
        return State::NORMAL;
}

// read from sensor and return formatted value (% | °C) as string
String Sensor::readSensor() {
    int value = analogRead(this->pin); // read from sensor
    value = this->minMaxRange.formatValue(this->name, value); // format value to account for min and max values
    value = map(value, this->minMaxRange.getMinValue(), this->minMaxRange.getMaxValue(), 0, 100); // map value to 0-100 range
    Serial.println(this->name + " value: " + String(value) + "%"); // print value
    return String(value) + "%";
}

