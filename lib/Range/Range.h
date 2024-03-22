#include <Arduino.h>

#ifndef Range_H
#define Range_H

template <typename T>
class Range
{
private:
    T minValue, maxValue; // min and max values

public:
    Range(T minValue, T maxValue) {
        this->minValue = minValue; // set min value
        this->maxValue = maxValue; // set max value
    }

    // format value to account for min and max values
    T formatValue(String name, T value, bool invert = true) {
        if (value < this->minValue) { // if value is below minimum value
            Serial.println("Calibration: " + name + " value (" + String(value) + ") is below minimum value (" + String(this->minValue) + ")"); // print error message
            value = this->minValue; // set value to minimum value
        } else if (value > this->maxValue) { // if value is above maximum value
            Serial.println("Calibration: " + name + " value (" + String(value) + ") is above maximum value (" + String(this->maxValue) + ")");
            value = this->maxValue; // set value to maximum value
        }

        if (invert) // if invert is true
            value = map(value, this->minValue, this->maxValue, this->maxValue, this->minValue); // invert value
        return value;
    }

    // check if value is within range
    bool isInRange(T value) {
        return (value >= this->minValue && value <= this->maxValue); // return true if value is within range
    }

    T getMinValue() {
        return this->minValue; // return min value
    }
    T getMaxValue() {
        return this->maxValue; // return max value
    
    }
};

#endif