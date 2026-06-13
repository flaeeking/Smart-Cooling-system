# Smart Cooling System

## Overview

This project is an ESP32-based smart cooling system designed to control fan speed through both Hand Distance-based control and automatic temperature regulation. The system integrates multiple sensors and control modes to provide a responsive and user-friendly cooling solution while demonstrating key embedded systems concepts such as sensor interfacing, PWM control, ADC measurements, and real-time processing.

## Features

* Distance-based fan speed control using an ultrasonic sensor
* Automatic temperature-based control using an NTC thermistor
* PWM-based motor speed regulation
* OLED display providing real-time system feedback
* Manual and automatic operating modes
* Real-time temperature and distance monitoring

## Hardware Components

* ESP32 Development Board
* HC-SR04 Ultrasonic Sensor
* NTC Thermistor
* SSD1306 OLED Display
* DC Fan / Motor
* Supporting resistors and wiring
* 6v battery pack
* breadboard
* button

## System Operation

### Manual Mode

The ultrasonic sensor measures the distance between the user's hand and the sensor. This distance is mapped to a PWM signal that controls the fan speed, allowing touchless adjustment of cooling intensity.

### Automatic Mode

The NTC thermistor continuously monitors ambient temperature. The ESP32 processes the sensor readings and automatically adjusts fan speed according to room temperature, increasing cooling when higher temperatures are detected.

### User Interface

An OLED display provides live feedback including:

* Room temperature
* Hand distance from sensor
* Fan speed
* Current operating mode

## Engineering Challenges

During development, several challenges were encountered:

* Calibrating the ultrasonic sensor for stable distance measurements
* Mapping distance values to smooth fan speed changes
* Converting thermistor readings into accurate temperature measurements
* Integrating multiple operating modes without affecting system responsiveness
* Ensuring reliable real-time updates on the OLED display
* Designing a suitable power distribution system for the ESP32 and motor while maintaining stable operation
* Calibrating the NTC thermistor for correct temprature measurements

Solving these issues improved my understanding of embedded software architecture, sensor calibration, PWM motor control, and hardware-software integration.

## Skills Demonstrated

* Embedded Systems Development
* ESP32 Programming
* PWM Motor Control
* Sensor Interfacing
* ADC Measurements
* Real-Time Processing
* Control System Design
* Hardware-Software Integration
* Debugging and System Testing
* circuit integration and component selection

## Future Improvements

Potential future enhancements include:

* Wi-Fi monitoring dashboard
* Mobile application integration
* Data logging and analytics
* Advanced control algorithms
* Energy consumption monitoring

## Project Outcome

This project strengthened my understanding of how embedded systems combine sensing, computation, and control to create intelligent real-time systems. It also provided practical experience in integrating multiple hardware and software components into a single functional device.
