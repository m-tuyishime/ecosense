#include "Sensor.h"

// constructor
Sensor::Sensor(byte pin, String name, String shortName, Range<int> minMaxRange, Range<byte> critPercRange) : 
    pin(pin), name(name), shortName(shortName), minMaxRange(minMaxRange), critPercRange(critPercRange) {} // sets all properties values of the sensor

// return 2 messages for LCD rows
StringArray2 Sensor::getCritMessages() {
    StringArray2 criticalValues; // create array of 2 strings
    String sign = this->shortName == "AIR_T" ? "°C" : "%"; // set sign to "°C" if shortName is "AIR_T" else set to "%"
    criticalValues.arr[0] = this->name + ": " + this->readSensor(); // first message (ex. "Light: 50%")
    State status = this->isCritical(); // check if value is critical
    if (status == State::NORMAL) // if value is normal
        return {"", ""}; // return empty strings
    else if (status == State::TOO_HIGH) // if value is below lowCritPerc
        criticalValues.arr[1] = "Reduce to "; // second message (ex. "Reduce to 50% - 80%")
    else
        criticalValues.arr[1] = "Increase to "; // second message (ex. "Increase to 50% - 80%")
    criticalValues.arr[1] += String(this->critPercRange.getMinValue()) + sign + " - " + String(this->critPercRange.getMaxValue()) + sign; // add critical percentage range to second message
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
    Serial.println(this->name + " value: " + String(value) + "%"); // print value to serial monitor
    return String(value) + "%";
}

