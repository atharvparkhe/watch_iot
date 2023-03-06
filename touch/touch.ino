unsigned long chrono = 0;

void setup() {
  chrono = millis();
  Serial.begin (115200);
}

void loop() {
  if (millis() - chrono >= 1000) {
    chrono = millis();
    Serial.println(chrono);
  }
  // you can do other things here
}
