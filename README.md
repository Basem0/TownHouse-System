# Smart Townhouse Project

Welcome to the Smart Townhouse project! This project aims to create an intelligent system for monitoring and controlling various aspects of a townhouse, including home and garage functionalities. The system utilizes ESP microcontrollers connected to sensors, providing real-time data and control through a Kotlin mobile app.

## Features

### Home Module

1. **Earthquake Detection:**
   - Utilizes MPU6050 gyroscope to detect and measure seismic activity.
   - Notifies users in case of an earthquake through the mobile app.

2. **Gas Leak Monitoring:**
   - Integrates MQ-4 gas detector to measure methane/natural gas concentration.
   - Sends real-time gas level data to the mobile app for monitoring.

3. **Temperature and Humidity Sensing:**
   - Uses DHT11 sensor to measure ambient temperature and humidity.
   - Displays data on an LCD screen and updates the mobile app.

4. **Flame Detection:**
   - Incorporates a flame sensor to detect fire incidents.
   - Triggers water pump to extinguish fire and sends alerts to the mobile app.

5. **LCD Display:**
   - Shows real-time sensor data on a character LCD display.

### Garage Module

1. **Password-Protected Access:**
   - Features a membrane keypad for secure access to the garage.
   - Allows users to input a password to open the garage door.

2. **Fire Safety:**
   - Includes a flame sensor to detect fire incidents in the garage.

3. **Water Pump Control:**
   - Activates a water pump to extinguish fire in the garage.

## Components

- [Earthquake Detection: MPU6050 Gyroscope](https://lampatronics.com/product/gy-521-mpu6050-imu-3-axis-gyro-3-axis-accelerometer/)
- [Gas Leak Monitoring: MQ-4 Gas Detector](https://lampatronics.com/product/mq-4-methane-natural-gas-sensor-module/)
- [Temperature and Humidity Sensing: DHT11 Sensor](https://lampatronics.com/product/dht11-humidity-temperature-sensor-module/)
- [Flame Detection: Flame Sensor Module](https://lampatronics.com/product/flame-sensor-module/)
- [LCD Display: Character LCD 2x16 (Blue)](https://lampatronics.com/product/character-lcd-2x16-blue-with-soldering-pin-header/)
- [Garage Access: Membrane Keypad 4x4](https://lampatronics.com/product/membrane-keypad-4x4/)
- [Water Pump Control: Mini DC Water Pump 3-6V, 120L/h](https://lampatronics.com/product/water-pump-mini-dc-3-6v-120l-h/)
- [Secure Access: Arduino Uno SMD R3](https://lampatronics.com/product/arduino-uno-smd-r3-without-cable/)
- [Garage Safety: IR 5mm Infrared Obstacle Avoidance Sensor](https://lampatronics.com/product/ir-5mm-infrared-obstacle-avoidance-sensor-4pin-module/)

## Mobile App

- [Kotlin Mobile App](#) *(Link to be added when available)*

## How to Use

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/smart-townhouse.git
