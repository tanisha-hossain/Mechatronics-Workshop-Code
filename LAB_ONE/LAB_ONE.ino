#include "arduino_secrets.h"

#define LED 2
/*

*/

void setup() {
Serial.begin(15200);
pinMode(LED,OUTPUT);
}


void loop() {
  Serial.println("hello world");
  digitalWrite(LED,HIGH);
  delay(2000);
  digitalWrite(LED,LOW);
  delay(2000);
}



