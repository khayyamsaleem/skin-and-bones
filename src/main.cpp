#include <Arduino.h>
#include "ESP8266WiFi.h"

const char *ssid = "Stevens-Media";
const char *password = "Stevens1870";

void setup()
{
  pinMode(D8, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.print("Connected! IP: ");
  Serial.println(WiFi.localIP());
  delay(5000);
}

void loop()
{
  digitalWrite(D8, HIGH);
  delay(1000);
  digitalWrite(D8, LOW);
  delay(1000);
}