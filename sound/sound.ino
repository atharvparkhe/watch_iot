
int sensorPin = A0;
int sensorValue = 0;
long time_start, time_measure;
int sound, sound_min, sound_max, sound_amplitude;
int decibel;

void setup()
   {
    Serial.begin(9600);

    time_measure = 50;   // time in ms within the signal is being analyzed
   }

void loop()
   {
    sound = analogRead(sensorPin);
    //Serial.println(sound);
 
    sound_min = 1024;
    sound_max = 0;
 
    time_start = millis();
 
    while(millis() - time_start < time_measure)
       {
        sound = analogRead(sensorPin);
 
        if(sound > sound_max)
           {
            sound_max = sound;
           }
        else if(sound < sound_min)
           {
            sound_min = sound;
           }
       }
 
    sound_amplitude = sound_max - sound_min;

    decibel = map(sound_amplitude, 0, 700, 40, 110);   // conversion of the amplitude to decibel

    Serial.println(decibel);

    delay(100);
   }
