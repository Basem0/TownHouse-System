#ifndef ULTRASONIC_FUNCTIONS_H
#define ULTRASONIC_FUNCTIONS_H

#include <NewPing.h>

#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define TRIGGER_PIN  A3  // Arduino pin tied to trigger pin on the ping sensor.
#define ECHO_PIN     A2  // Arduino pin tied to echo pin on the ping sensor.

NewPing ultra(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
float Sensor, bestUltra, oldUltra;

void ReadSensors(){
  Sensor = ultra.ping_cm();
  bestUltra = (Sensor + oldUltra) / 2;
  oldUltra = bestUltra;
}

#endif  // ULTRASONIC_FUNCTIONS_H
