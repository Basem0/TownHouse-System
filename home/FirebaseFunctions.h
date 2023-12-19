#ifndef FIREBASE_FUNCTIONS_H
#define FIREBASE_FUNCTIONS_H

#include <Arduino.h>

#define WIFI_SSID       "*****"
#define WIFI_PASSWORD   "*****"
#define API_KEY         "*****"
#define DATABASE_URL    "*****"

extern FirebaseData fbdo;
extern FirebaseAuth auth;
extern FirebaseConfig config;
extern bool signupOK;

extern const char *fcmEndpoint;
extern const char *firebaseServerKey;

void sendCustomMessage(const String &message, const String &Father, const String &Son);
void sendFCMNotificationToTopic(const String &message, const String &topic);
void sendCustomMessageFromSerial();
void setupWiFiAndFirebase();

#endif
