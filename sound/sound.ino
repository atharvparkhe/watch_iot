
#define SENSOR_PIN 34

void setup() {
   pinMode(SENSOR_PIN, INPUT);
   Serial.begin(115200);
}

void loop() {
  
   int db = digitalRead(SENSOR_PIN);

   Serial.println(db);


 
}
