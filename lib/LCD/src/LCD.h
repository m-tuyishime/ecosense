#include <Arduino.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>


#ifndef LCD_H
#define LCD_H

class LCD
{
private:
    hd44780_I2Cexp lcd; // LCD object
public:
    LCD(); // constructor
    void init(); // initialize the LCD
    void print(String message, bool row); // print the message on a specific row of the LCD
    void clear(); // clear the LCD
};

#endif
