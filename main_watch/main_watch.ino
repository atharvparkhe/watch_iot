
#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

//#include <Wire.h>
//#include <BH1750.h>

//#include "MAX30100_PulseOximeter.h"
//BH1750 lightMeter;

//#define REPORTING_PERIOD_MS 1000

//PulseOximeter pox;

//float BPM, SpO2;
//uint32_t tsLastReport = 0;

// WiFi Credentials
#define WIFI_SSID "honor"
#define WIFI_PASSWORD "12345678"

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

int heartBeat_value, light_value, oxygen_value, sound_value, touch_value;

//float temperature_value;

void setup() {

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.reconnectWiFi(true);
  Firebase.begin(DATABASE_URL, API_KEY);
  Firebase.setDoubleDigits(5);

  pinMode(2, OUTPUT);  // inbuilt LED for WiFi status



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

    digitalWrite(2, HIGH);

    //    Set Variables
//        Firebase.setFloat(fbdo, "/Sensor/temperature", 10);
    //    Firebase.setInt(fbdo, "/Sensor/heartBeat", 11);
    //    Firebase.setInt(fbdo, "/Sensor/oxygen", 12);
    //    Firebase.setInt(fbdo, "/Sensor/sound", 13);
    //    Firebase.setInt(fbdo, "/Sensor/light", 14);
    //    Firebase.setInt(fbdo, "/Sensor/touch", 15);

//    Firebase.pushString("/Sensor/temperature", String(12.4)); 
    //    Firebase.setInt(fbdo, "/Sensor/oxygen", 14);

    Firebase.getFloat(fbdo, "/Sensor/temperature");
    String temperature_value = fbdo.to<String>();

    Firebase.getInt(fbdo, "/Sensor/heartBeat");
    heartBeat_value = fbdo.to<int>();

    Firebase.getInt(fbdo, "/Sensor/light");
    light_value = fbdo.to<int>();

    Firebase.getInt(fbdo, "/Sensor/oxygen");
    oxygen_value = fbdo.to<int>();

    Firebase.getInt(fbdo, "/Sensor/sound");
    sound_value = fbdo.to<int>();

    Firebase.getInt(fbdo, "/Sensor/touch");
    touch_value = fbdo.to<int>();

    FirebaseJson json;

    //  Printing Data
    Serial.print("temperature:");
    Serial.print(temperature_value);
    Serial.print(" heartBeat: ");
    Serial.print(heartBeat_value);
    Serial.print(" oxygen: ");
    Serial.print(oxygen_value);
    Serial.print(" sound: ");
    Serial.print(sound_value);
    Serial.print(" light: ");
    Serial.print(light_value);
    Serial.print(" touch: ");
    Serial.println(touch_value);



    delay(100);

  }

}
