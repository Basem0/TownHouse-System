#include "MPU6050Functions.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

int LastTime = 0;
float x = 0, y = 0, z = 0;
float XError = 0, YError = 0, ZError = 0;

volatile bool interruptFlag = false;
const float threshold = 0.05;

void handleInterrupt() {
    interruptFlag = true;
}

void def_gyro() {
    while (!Serial)
        delay(10);  // will pause Zero, Leonardo, etc until serial console opens
    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        while (1) {
            delay(10);
        }
    }
    Serial.println("MPU6050 Found!");

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    Serial.print("Accelerometer range set to: ");
    switch (mpu.getAccelerometerRange()) {
        case MPU6050_RANGE_2_G:
            Serial.println("+-2G");
            break;
        case MPU6050_RANGE_4_G:
            Serial.println("+-4G");
            break;
        case MPU6050_RANGE_8_G:
            Serial.println("+-8G");
            break;
        case MPU6050_RANGE_16_G:
            Serial.println("+-16G");
            break;
    }
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    Serial.print("Gyro range set to: ");
    switch (mpu.getGyroRange()) {
        case MPU6050_RANGE_250_DEG:
            Serial.println("+- 250 deg/s");
            break;
        case MPU6050_RANGE_500_DEG:
            Serial.println("+- 500 deg/s");
            break;
        case MPU6050_RANGE_1000_DEG:
            Serial.println("+- 1000 deg/s");
            break;
        case MPU6050_RANGE_2000_DEG:
            Serial.println("+- 2000 deg/s");
            break;
    }

    mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
    Serial.print("Filter bandwidth set to: ");
    switch (mpu.getFilterBandwidth()) {
        case MPU6050_BAND_260_HZ:
            Serial.println("260 Hz");
            break;
        case MPU6050_BAND_184_HZ:
            Serial.println("184 Hz");
            break;
        case MPU6050_BAND_94_HZ:
            Serial.println("94 Hz");
            break;
        case MPU6050_BAND_44_HZ:
            Serial.println("44 Hz");
            break;
        case MPU6050_BAND_21_HZ:
            Serial.println("21 Hz");
            break;
        case MPU6050_BAND_10_HZ:
            Serial.println("10 Hz");
            break;
        case MPU6050_BAND_5_HZ:
            Serial.println("5 Hz");
            break;
    }

    Serial.println("");
    delay(10);

    // calibration
    for (int i = 0; i < 200; i++) {
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
        XError += g.gyro.x;
        YError += g.gyro.y;
        ZError += g.gyro.z;
    }
    XError /= 200.0;
    YError /= 200.0;
    ZError /= 200.0;
    LastTime = millis();
}

float gyro(int *temper) {
    /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    int Time = millis();
    int dt = Time - LastTime;
    float Sum;
    Sum = (g.gyro.z - ZError);
    if (fabs(Sum) > threshold) {
        z += Sum * dt / 1000.0 * 180 / 3.14159;
        interruptFlag = true;  // Set the interruptFlag to activate the interrupt
    }
    LastTime = Time;

    Serial.print("Z: ");
    Serial.print(z);
    Serial.println(" degree");
    *temper = temp.temperature;
    return z;
}
