#include <Wire.h>
#include <BH1750.h>

#include "MAX30100_PulseOximeter.h"
//BH1750 lightMeter;
 
#define REPORTING_PERIOD_MS 1000

PulseOximeter pox;

int touch_pin=34;

int sound_pin=33;
 
float BPM, SpO2;
uint32_t tsLastReport = 0;
 
void onBeatDetected() {
    Serial.println("Beat Detected!");
}

void setup() {
    Serial.begin(115200);

    pinMode(19, OUTPUT);
    
    pinMode(touch_pin, INPUT);
    pinMode(sound_pin, INPUT);
    
    Serial.print("Initializing Pulse Oximeter..");

    if (!pox.begin()) {
         Serial.println("FAILED");
         for(;;);
    } else {
         Serial.println("SUCCESS");
         pox.setOnBeatDetectedCallback(onBeatDetected);
    }
        pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);


//    Wire.begin();
//    lightMeter.begin();
}


void loop() {
    pox.update();
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
//    float lux = lightMeter.readLightLevel();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(BPM);
        Serial.print(" bpm / SpO2:");
        Serial.println(SpO2);
        tsLastReport = millis();
    }
    if(digitalRead(touch_pin)==HIGH){
      Serial.println("touched");  
    }
    if(digitalRead(sound_pin)==HIGH){
      Serial.println("loud sound");  
    }

    
    
}
