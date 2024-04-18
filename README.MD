# Arduino Environment Monitor

This project is an environment monitor using an Arduino Uno R3. It was created by Muhoza Olivier Tuyishime and Tagne Nzeuguem Igor Laurel as part of the Winter 2924 INF1643-01 Architecture des ordinateurs II course at Universtité du Québec en Outaouais.

## Hardware

The following hardware is used in this project:

- Arduino Uno R3
- DHT11 Temperature and Humidity Sensor (connected to digital pin D2)
- KY-018 Photoresistor (connected to analog pin A0)
- 16x2 LCD with I2C interface (connected to SDA and SCL)

## Software

This project was developed using PlatformIO, an open-source ecosystem for IoT development.

## Setup

1. Install PlatformIO.
2. Clone this repository to your local machine.
3. Open the project in PlatformIO.
4. Connect your Arduino Uno to your computer via USB.

## Upload and Run

1. In PlatformIO, select the correct board (Arduino Uno) and port.
2. Click the "Upload" button to compile the code and upload it to your Arduino.
3. Once the upload is complete, the Arduino will automatically reset and start running the program.

Please ensure that the hardware is connected as described above before uploading the program.
