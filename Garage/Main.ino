#include "KeypadFunctions.h"
#include "UltrasonicFunctions.h"
#include "FlameSensorFunctions.h"

#include <Servo.h>

#define red_led 10
#define yellow_led 11
#define green_led 12

String password = "2580";
String enteredPassword = "";

Servo myservo;  // create a servo object to control a servo
int pos = 0;    // variable to store the servo position

void pumpOn(){
  analogWrite(A0, 255);
  digitalWrite(13, HIGH);
}

void pumpOff(){
  analogWrite(A0, 255);
  digitalWrite(13, LOW);
}

void setup() {
  Serial.begin(9600);
  myservo.attach(A1);  // attaches the servo on pin A1 to the servo object
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  // Set the default state
  digitalWrite(yellow_led, HIGH);
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  myservo.write(160);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(flame_sensor_pin, INPUT);     // declaring sensor pin as an input pin for Arduino
  pinMode(13, OUTPUT);
}

void handleCorrectPassword() {
  digitalWrite(green_led, HIGH);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);
  myservo.write(90);
  delay(15);
  delay(1000);
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(red_led, LOW);
}

void handleIncorrectPassword() {
  myservo.write(160);
  for (int i = 0; i < 3; i++) {
    digitalWrite(red_led, HIGH);
    delay(500);
    digitalWrite(red_led, LOW);
    delay(500);
  }
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(red_led, LOW);
}

void loop() {
  char key = keypad.getKey();
  ReadSensors();
  Serial.println(bestUltra);

  if (key) {
    Serial.println(key);

    if (key == '#') {
      if (enteredPassword == password) {
        handleCorrectPassword();
      } else {
        handleIncorrectPassword();
      }

      enteredPassword = "";
      delay(100);
    } else {
      enteredPassword += key;
      myservo.write(160);
    }
  }

  ReadFlameSensor();

  if (flame_pin == LOW) {
    Serial.println("FLAME, FLAME, FLAME");
    pumpOn();
  } else {
    Serial.println("no flame");
    pumpOff();
  }
}
