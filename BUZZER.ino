#include "Arduino.h"
#define buzzer 2
#define button 18
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(button,INPUT_PULLUP);

}

void loop() {
  if(digitalRead(button)==0)
  {
    for(int i=0; i<4;i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
    }
  }

}
