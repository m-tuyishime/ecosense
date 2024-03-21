#include "LCD.h"

LCD::LCD()
{
    
}

// initialize the LCD
void LCD::init() {
    hd44780_I2Cexp lcd; // LCD object
    this->lcd = lcd;
    int status = this->lcd.begin(16, 2); // initialize the LCD with 16 columns and 2 rows
    Serial.println("LCD Status: " + String(status)); // print the status to the serial monitor
    this->lcd.setBacklight(255); // turn on the backlight
    this->lcd.clear(); // clear the LCD
    this->lcd.home(); // set the cursor to the first column of the first row
}


// print the message on a specific row of the LCD
void LCD::print(String message, bool row) {
    delay(3000); // wait for a second
    if (message.length() > 16) 
        Serial.println("Error: message is too long");

    this->lcd.setCursor(0, row); // set the cursor to the first column of row
    this->lcd.print(message); // print the string
    Serial.println("LCD Row" + String(row) + ": " + message); // print the message to the serial monitor
}

// clear the LCD
void LCD::clear() {
    this->lcd.clear(); // clear the LCD
    Serial.println("LCD Cleared!"); // print the message to the serial monitor
}