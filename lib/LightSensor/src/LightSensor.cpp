#include "LightSensor.h"

// constructor
LightSensor::LightSensor(byte pin, Range<byte> critPercRange, byte lightThreshPerc) : 
    Sensor(pin, "Light", "LIGHT", Range<int>(0, 1023), critPercRange), lightThreshPerc(lightThreshPerc) {
    this->currentSec = 0; // set current second to 0
    this->lastMillis = 0; // set last millisecond to 0
    this->checkQuota = false; // set checkQuota to false
    Serial.println("hallaaa");
}

// get light value for a specific second
byte LightSensor::getDaylightSec(unsigned long sec) {
    return bitRead(this->daylightSecs[sec / 8], sec % 8); // get light value for a specific second
}

// set light value for a specific second
void LightSensor::setDaylightSec(unsigned long sec, byte light) {
    bitWrite(this->daylightSecs[sec / 8], sec % 8, light); // set light value for a specific second
}

// increment current second and set value in daylightSecs array
void LightSensor::incSec () {
    if (abs(millis() - this->lastMillis) < 1000)  // if 1 second has not passed
        delay(1000 - abs(millis() - this->lastMillis)); // wait for 1 second - time passed

    this->lastMillis = millis(); // set last millisecond to current milliseconds
    if (this->currentSec == sizeof(this->daylightSecs) / sizeof(this->daylightSecs[0])) { // if a day has passed
        this->checkQuota = true; // start checking quota
        this->currentSec = 0; // reset current second to 0
    }

    bool light = analogRead(this->pin) > this->lightThreshPerc; // check if light is above threshold
    this->setDaylightSec(this->currentSec++, light); // set light value for a specific second and increment current second
}

// read from sensor and return formatted value (%) as string
String LightSensor::readSensor() {
    incSec(); // increment current second 
    int value = analogRead(this->pin); // read from sensor
    value = this->minMaxRange.formatValue(this->name, value); // format value to account for min and max values
    value = map(value, this->minMaxRange.getMinValue(), this->minMaxRange.getMaxValue(), 0, 100); // map value to 0-100 range
    Serial.println(this->name + " value: " + String(value) + "%"); // print value to serial monitor
    return String(value) + "%";
}

// check if value is outside of range (TOO_LOW, TOO_HIGH, NORMAL)
State LightSensor::isCritical() {
    incSec(); // increment current second
    int value = 0; // create variable to store total seconds of daylight
    for (unsigned long i = 0; i < 86400; i++) // for each second of the day
        value += this->getDaylightSec(i);  // increment value if light is above threshold
    value = value / sizeof(this->daylightSecs) / sizeof(this->daylightSecs[0]) * 100; // calculate percentage of daylight in a day above threshold
    if (checkQuota && map(value, this->minMaxRange.getMinValue(), this->minMaxRange.getMaxValue(), 0, 100) < this->critPercRange.getMinValue()) // if value is below lowCritPerc
        return State::TOO_LOW;
    else if (checkQuota && map(value, this->minMaxRange.getMinValue(), this->minMaxRange.getMaxValue(), 0, 100) > this->critPercRange.getMaxValue()) // if value is above highCritPerc
        return State::TOO_HIGH;
    else
        return State::NORMAL;
}


// // return 2 messages for LCD rows
StringArray2 LightSensor::getCritMessages() {
    StringArray2 criticalValues; // create array of 2 strings
    State status = this->isCritical(); // check if value is critical
    if (status == State::NORMAL) // if value is normal
        return {"", ""}; // return empty strings
    else if (status == State::TOO_HIGH) // if value is below lowCritPerc
        criticalValues.arr[1] = "Reduce to "; // second message (ex. "Reduce to 50% - 80%")
    else
        criticalValues.arr[1] = "Increase to "; // second message (ex. "Increase to 50% - 80%")
    criticalValues.arr[1] += String(this->critPercRange.getMinValue() / 100 * 24) + "h - " + String(this->critPercRange.getMaxValue() / 100 * 24) + "h"; // add critical percentage range to second message

    unsigned long secs = 0; // create variable to store total seconds of daylight
    for (unsigned long i = 0; i < 86400; i++) // for each second of the day
        secs += this->getDaylightSec(i); // increment value if light is above threshold

    criticalValues.arr[0] = "Daylight Hours: " + String(secs / 3600) + "h " + String((secs % 3600) / 60) + "m"; // first message (ex. "Daylight Hours: 12h 30m")
    return criticalValues;
}
