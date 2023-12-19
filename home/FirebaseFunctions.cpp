#include "FirebaseFunctions.h"
#include <Arduino.h>
#include <HTTPClient.h>
#include <Firebase_ESP_Client.h>

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
bool signupOK = false;

void sendCustomMessage(const String &message, const String &Father, const String &Son) {
    if (Firebase.ready() && signupOK) {
        String Location = Father + "/" + Son;

        if (Firebase.RTDB.setString(&fbdo, Location.c_str(), message)) {
            Serial.println("Message Sent to RTDB");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
        } else {
            Serial.println("Failed to send message to RTDB");
            Serial.println("REASON: " + fbdo.errorReason());
        }
    }
}

void setupWiFiAndFirebase() {
    const char *ssid = WIFI_SSID;
    const char *password = WIFI_PASSWORD;

    WiFi.begin(ssid, password);

    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    config.api_key = API_KEY;
    config.database_url = DATABASE_URL;

    if (Firebase.signUp(&config, &auth, "", "")) {
        Serial.println("Firebase signup successful");
        signupOK = true;
    } else {
        Serial.printf("Firebase signup failed: %s\n", config.signer.signupError.message.c_str());
    }

    config.token_status_callback = tokenStatusCallback;
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}
