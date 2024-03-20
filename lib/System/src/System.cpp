// print the values of the sensors on the LCD in real time for count + 1 seconds
void LCD::printSensors(int count) {
    lcd.clear(); // clear the lcd
    String row1 = "Light: " + lightSensor.readSensor();
    // row1 += " Temp: " + tempSensor.readSensor(); ///////////////////////////////////////////////////////////////////////////////////////////
    String row2 = "Soil Humidity: " + soilHumiditySensor.readSensor();
    printLCD(row1, 0); // print the light and temperature to the first row
    printLCD(row2, 1); // print the soil humidity to the second row
    delay(1000); // wait for a second
    if (count > 0) // check if the count is greater than 0
        printSensors(count - 1); // call the function recursively (count - 1 times)
}

// print the details of critical values on the LCD
void LCD::printDetails() {
    // Sensor sensors[] = {lightSensor, soilHumiditySensor, tempSensor}; ///////////////////////////////////////////////////////////////////////////////////////////
    Sensor sensors[] = {lightSensor, soilHumiditySensor}; 
    for (Sensor sensor : sensors) { // loop through the sensors
        if (sensor.isCritical()) {
            lcd.clear(); // clear the lcd
            StringArray2 messages = sensor.printCritical(); // get the critical messages
            printLCD(messages.arr[0], 0); // print the first message on the first row
            printLCD(messages.arr[1], 1); // print the second message on the second row
            delay(1000); // wait for a second
        }
    }
}