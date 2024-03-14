#include "Sensor.h"

Sensor::Sensor(uint8_t pin, String name) {
    this->pin = pin; // set analog pin
    this->name = name; // set sensor name
}

// return 2 messages for LCD rows
String[] Sensor::printCritical() {
    String[] criticalValues; // create array of 2 strings
    criticalValues[0] = this->name + ": " + this->readSensor(); // first message (ex. "Light: 50%")
    int8_t status = this->isCritical() // check if value is critical
    if (status == 1) // if value is below lowCritPerc
        criticalValues[1] = "Reduce to " // second message (ex. "Reduce to 50% - 80%")
    else
        criticalValues[1] = "Increase to " // second message (ex. "Increase to 50% - 80%")
    criticalValues[1] += String(this->lowCritPerc) + "% - " + String(this->highCritPerc) + "%"; // add lowCritPerc and highCritPerc range to second message
    return criticalValues;
}

// format sensor value to account for min and max values
uint16_t Sensor::formatValue(uint16_t value) {
    if (value < this->minValue) { // if value is below minimum value
        Serial.println("Calibration: " + this->name + " value (" + String(value) + ") is below minimum value (" + String(this->minValue) + ")"); // print error message
        value = this->minValue; // set value to minimum value
    } else if (value > this->maxValue) { // if value is above maximum value
        Serial.println("Calibration: " + this->name + " value (" + String(value) + ") is above maximum value (" + String(this->maxValue) + ")");
        value = this->maxValue; // set value to maximum value
    }
    return value;
}

// check if value is outside of lowCritPerc and highCritPerc range (1: low, 0: high, -1: normal)
int8_t Sensor::isCritical() {
    uint16_t value = this->analogRead();
    value = this->formatValue(value);
    if (map(value, this->minValue, this->maxValue, 0, 100) < this->lowCritPerc) // if value is below lowCritPerc
        return 1;
    else if (map(value, this->minValue, this->maxValue, 0, 100) > this->highCritPerc) // if value is above highCritPerc
        return 0;
    return -1; // if value is within lowCritPerc and highCritPerc
}

// read from sensor and return formatted value (% | °C) as string
String Sensor::readSensor() {
    uint16_t value = this->analogRead(); // read from sensor
    value = this->formatValue(value); // format value
    value = map(value, this->minValue, this->maxValue, 0, 100); // map value to percentage
    return String(value) + "%";
}