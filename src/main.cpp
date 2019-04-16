#include <Arduino.h>
#include <Servo.h>
#include "ESP8266WiFi.h"

Servo s;

void setup()
{
  Serial.begin(9600);
  s.attach(D8);
  // put your setup code here, to run once:
}

void loop()
{
  for (int i = 0; i < 180; i++)
  {
    s.write(i);
    delay(2);
  }
  delay(50);
  for (int i = 180; i >= 0; i--)
  {
    s.write(i);
    delay(2);
  }
  Serial.println("rotated");
  delay(1000);
}