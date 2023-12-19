# Smart Townhouse Project
Welcome to the Smart Townhouse project! This project aims to create an intelligent system for monitoring and controlling various aspects of a townhouse, including home and garage functionalities. The system utilizes ESP microcontrollers connected to sensors, providing real-time data and control through a Kotlin mobile app.

Features
Home Module
Earthquake Detection:

Utilizes MPU6050 gyroscope to detect and measure seismic activity.
Notifies users in case of an earthquake through the mobile app.
Gas Leak Monitoring:

Integrates MQ-4 gas detector to measure methane/natural gas concentration.
Sends real-time gas level data to the mobile app for monitoring.
Temperature and Humidity Sensing:

Uses DHT11 sensor to measure ambient temperature and humidity.
Displays data on an LCD screen and updates the mobile app.
Flame Detection:

Incorporates a flame sensor to detect fire incidents.
Triggers water pump to extinguish fire and sends alerts to the mobile app.
LCD Display:

Shows real-time sensor data on a character LCD display.
Garage Module
Password-Protected Access:

Features a membrane keypad for secure access to the garage.
Allows users to input a password to open the garage door.
Fire Safety:

Includes a flame sensor to detect fire incidents in the garage.
Water Pump Control:

Activates a water pump to extinguish fire in the garage.
Components
Earthquake Detection: MPU6050 Gyroscope
Gas Leak Monitoring: MQ-4 Gas Detector
Temperature and Humidity Sensing: DHT11 Sensor
Flame Detection: Flame Sensor Module
LCD Display: Character LCD 2x16 (Blue)
Garage Access: Membrane Keypad 4x4
Water Pump Control: Mini DC Water Pump 3-6V, 120L/h
Secure Access: Arduino Uno SMD R3
Garage Safety: IR 5mm Infrared Obstacle Avoidance Sensor
Mobile App
Kotlin Mobile App (Link to be added when available)
How to Use
Clone the Repository:

bash
Copy code
git clone https://github.com/your-username/smart-townhouse.git
Set Up Arduino IDE:

Open the Arduino IDE and install necessary libraries for sensors and modules.
Connect Components:

Wire the components according to the provided schematic diagrams.
Upload Code:

Upload the Arduino code to the ESP microcontrollers.
Run the Kotlin App:

Build and run the Kotlin app on your Android device.
Explore Smart Townhouse:

Access real-time data, control garage access, and receive alerts through the mobile app.
Contributors
Your Name
Contributor 2
Contributor 3
License
This project is licensed under the MIT License.

Feel free to contribute, report issues, or suggest enhancements. Happy coding! 🚀
