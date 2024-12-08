#include "Arduino.h"
#define TrigPin 5
#define EchoPin 18
#define Sound_speed 0.034
#define cm_to_inch 0.393701  // Corrected conversion factor
long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // Measure the echo pulse duration
  duration = pulseIn(EchoPin, HIGH);

  // Calculate the distance in cm and inches
  distanceCm = duration * Sound_speed / 2;
  distanceInch = distanceCm * cm_to_inch;

  // Print the results to the Serial Monitor
  Serial.print("DISTANCE (CM): ");
  Serial.println(distanceCm);
  Serial.print("DISTANCE (INCH): ");
  Serial.println(distanceInch);

  delay(1000);  // Wait for 1 second before the next measurement
}
