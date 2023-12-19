#include "GasSensor.h"
const int AO_Pin = 4;   // Connect AO of MQ4 with Analog channel 0 pin (A0) of Arduino
const int DO_Pin = 16;  // Connect DO of MQ4 with Digital pin 8 (D8) of Arduino

int Gas() {
    int thresholdValue;  // A variable to store digital output of MQ4
    int analogOutput;    // Stores analog output of MQ4 sensor

    analogOutput = (analogRead(AO_Pin) * 255) / 4095;  // Take Analog output measurement sample from AO pin of MQ4 sensor
    thresholdValue = digitalRead(DO_Pin);              // Read digital output of MQ4 sensor

    // Uncomment the next lines if you need to print gas concentration and threshold to Serial
    // Serial.print("Methane Concentration: ");
    // Serial.println(analogOutput);
    // Serial.print("Threshold Value: ");
    // Serial.println(thresholdValue);

    return analogOutput;
}
