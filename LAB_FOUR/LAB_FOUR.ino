#include "arduino_secrets.h"

/*

*/
#define lightPin 34

int lightValue = 0;

void setup() {
  
    Serial.begin(9600);
    while(!Serial);
}

void loop() {
  
  lightValue = analogRead(lightPin);
  Serial.println("Current Reading>>");
  Serial.print("ADC Value:");
  Serial.println(lightValue);
  
  delay(5000);
}
