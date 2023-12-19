#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <HTTPClient.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#include "HumiditySensor.h"
#include "GasSensor.h"
#include "FirebaseFunctions.h"
#include "LCDFunctions.h"
#include "MPU6050Functions.h"

// Your constants and global variables here

void setup() {
    // Your setup code
    setupWiFiAndFirebase();
    LCDInitialization();
}

void loop() {
    // Your loop code
    loopHumidityGasAndGyro();
}
