
#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#include <Wire.h>
#include <BH1750.h>

//#include "MAX30100_PulseOximeter.h"
//BH1750 lightMeter;
 
#define REPORTING_PERIOD_MS 1000

//PulseOximeter pox;

float BPM, SpO2;
uint32_t tsLastReport = 0;

// WiFi Credentials
#define WIFI_SSID "Mango"
#define WIFI_PASSWORD "91641595"

// Firebase Credentials
#define API_KEY "CpTGOZjhDCY3DZHKV4G3DyNeyoSfMOLrIccY6mY9"
#define DATABASE_URL "https://watch-26765-default-rtdb.firebaseio.com/"

// Firebase RTDB Config
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// Sensor Pins Config
#define touch_sensor_pin 33
#define sound_sensor_pin 34


//void onBeatDetected() {
//    Serial.println("Beat Detected!");
//}

void setup() {

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.begin(DATABASE_URL, API_KEY);
  Firebase.setDoubleDigits(5);

  pinMode(19, OUTPUT);
    
  pinMode(touch_sensor_pin, INPUT);
  pinMode(sound_sensor_pin, INPUT);
  
//  Serial.print("Initializing Pulse Oximeter..");
//
//  if (!pox.begin()) {
//       Serial.println("FAILED");
//       for(;;);
//  } else {
//       Serial.println("SUCCESS");
//       pox.setOnBeatDetectedCallback(onBeatDetected);
//  }
//      pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

}

void loop() {

  if (Firebase.ready()) {

    digitalWrite(2,HIGH);
  
  }

}
