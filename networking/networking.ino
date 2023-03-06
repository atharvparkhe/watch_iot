#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

// WiFi Credentials
#define WIFI_SSID "Akash"
#define WIFI_PASSWORD "qwertyuiop"

// Firebase Credentials
#define API_KEY "CpTGOZjhDCY3DZHKV4G3DyNeyoSfMOLrIccY6mY9"
#define DATABASE_URL "https://watch-26765-default-rtdb.firebaseio.com/"

// Firebase RTDB Config
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.begin(DATABASE_URL, API_KEY);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Firebase.ready()) {
    digitalWrite(2,HIGH);
    Serial.println("Started");
    if(Firebase.setInt(fbdo, "/Values/Light", 12)){
      Serial.println("ok");
    } else {
      Serial.println(fbdo.errorReason().c_str());
    }
    Serial.println("Ended");
  }
}
