#include "arduino_secrets.h"

/*

*/
#define rainPin 5

//when the module detects rain the digital output goes LOW
bool rainState = HIGH;

void setup() {
  pinMode(rainPin, INPUT);
  
  Serial.begin(9600);
  while(!Serial);
    
}

void loop() {
  rainState = digitalRead(rainPin);
  
  if(!rainState) {
  
    Serial.println("Rain Detected");
    
    delay(5000);
  }
  
}
