# Internet-of-Things

# IoT Lab Tasks and Projects
This repository contains two projects related to IoT, focused on environmental monitoring and safety detection. The first project uses a soil moisture sensor in which characteristics like Response time, Hysterisis, and Sensitivity were measured, and the second involves gas detection using an MQ2 sensor, buzzer, ESP32, LCD, and Blynk for email notifications.

# 1. Soil Moisture Sensor
This project demonstrates the usage of a soil moisture sensor to monitor the moisture levels of soil. It's ideal for applications in agriculture, gardening, and smart farming, where monitoring soil health is essential.

# Components Used:
Soil Moisture Sensor

ESP32

# Features:
Real-time soil moisture data collection.
Can be used for automating irrigation systems based on moisture levels.
# Instructions:
Connect the soil moisture sensor to the ESP32 board.
Upload the code to the ESP32.
View the soil moisture data on the Blynk app.
# 2. Gas Detection System Using MQ2
This project focuses on detecting hazardous gas levels in the environment using the MQ2 gas sensor. It provides an alert system with a buzzer and displays the gas concentration on an LCD. Furthermore, it uses the ESP32 with Blynk for email notifications when unsafe gas levels are detected.

# Components Used:
MQ2 Gas Sensor

ESP32

Buzzer

LCD Display

Blynk App (for email notifications)

Dotted PCB

# Features:
Detects various gases (like methane, carbon monoxide) using the MQ2 sensor.
Provides an audible alert using a buzzer when gas levels exceed a threshold.
Displays gas concentration levels on an LCD.
Sends an email notification using Blynk when a dangerous gas concentration is detected.
# Instructions:
Connect the MQ2 gas sensor, LCD, buzzer, and ESP32 according to the wiring diagram.
Configure Blynk for email notification alerts.
Upload the code to the ESP32.
Test the system by exposing the MQ2 sensor to gas sources (safely).
Monitor the gas levels on the LCD and receive email alerts via Blynk.
# Dependencies:
Arduino IDE

Blynk App (Android/iOS)

ESP32 board libraries
# License:
This project is open source. Feel free to contribute or use it in your own IoT-based applications.

