#include <Arduino.h>

const int potPin = A2;
const int ledRed = 9;
const int ledGreen = 10;
const int ledBlue = 11;
const int buzzerPin = 8;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  int frequency = map(potValue, 0, 1023, 100, 2000);
  
  int redValue = map(potValue, 0, 1023, 0, 255);
  int greenValue = map(potValue, 0, 1023, 255, 0) / 2;
  int blueValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledRed, redValue);
  analogWrite(ledGreen, greenValue);
  analogWrite(ledBlue, blueValue);

  tone(buzzerPin, frequency);

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Buzzer Frequency: ");
  Serial.println(frequency);

  delay(100);
}