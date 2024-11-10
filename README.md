# Portable Temperature and Humidity Sensor
A portable temperature and humidity sensor with Arduino

## Overview

A compact, portable temperature and humidity sensor built with Arduino, featuring an LCD display for real-time data monitoring and a red LED indicator for unreadable values. This project is ideal for beginners and hobbyists interested in environmental sensing, with a focus on portability and ease of use. The setup includes a DHT sensor module for temperature and humidity readings, an LCD display for output, a red LED that alerts the user when values are non-readable, and a small rechargeable battery for power. Full code and wiring schematics are provided in this repository.


## Features

Real-time Temperature and Humidity Monitoring
Continuously displays accurate temperature and humidity readings from the DHT11 sensor on a 16x2 LCD screen, updated every few seconds. This display allows users to monitor environmental changes instantly, making it ideal for portable weather stations, greenhouse monitoring, and DIY environmental sensing projects.

Error Indication with Red LED
A built-in red LED signals the user when sensor data is unreadable, such as when the sensor encounters an error or is disconnected. This feature ensures the user is immediately aware of issues, providing a reliable way to identify and troubleshoot potential problems in real-time.

Adjustable LCD Contrast
Includes a 10k potentiometer to adjust the contrast of the 16x2 LCD screen, improving display visibility in various lighting conditions. This feature is especially useful when using the sensor outdoors or in different ambient lighting.

Portable Power Supply
Powered by a 9V battery connected through a breadboard power supply module, making it easy to take the device anywhere without the need for a direct power source. The portable design supports long-term use, ideal for mobile applications or places without stable power access.


## Required Components

Arduino Nano
DHT11 Temperature and Humidity Sensor
16x2 LCD Display
Red LED for error indication
10k Potentiometer for LCD contrast adjustment
10k Resistor (for DHT11)
330 Ohm Resistor (for LED)
Breadboard and connecting wires
9V Battery with breadboard power supply


## Setup and Usage

Connect Components:

Follow the provided circuit diagram to connect all components on the breadboard.

Refer to the provided photos for step-by-step guidance on connecting the LCD display and the DHT11 sensor to the breadboard. Provided images show the exact placement of each component, simplifying the wiring process.

Extra Explanation:

Connect the DHT11 sensor to the Arduino Nano and LCD display, and place a 10k pull-up resistor between the data pin of the DHT11 sensor and the VCC pin. This resistor stabilizes the data signal, ensuring accurate readings by "pulling up" the voltage level on the data line. Without this pull-up resistor, the signal could fluctuate, leading to unreliable or noisy readings.

Upload Code:

Use the Arduino IDE to upload the code to the Arduino Nano.
Ensure that the DHT library is installed in the Arduino IDE to enable communication with the DHT11 sensor.

Power Up:

Connect the 9V battery to the breadboard power supply to power the device.
Adjust the potentiometer to achieve the optimal contrast on the LCD screen.


## License
This project is open-source under the MIT License.




