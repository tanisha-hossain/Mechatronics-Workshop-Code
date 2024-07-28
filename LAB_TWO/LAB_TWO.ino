#include "arduino_secrets.h"

/*

*/
#define buzzerPin 14
void setup() {
  pinMode(buzzerPin,OUTPUT);
  
  Serial.begin(9600);
  while(!Serial);
    
}

void loop() {
  
  digitalWrite(buzzerPin, HIGH);
  Serial.println("Buzzer On");
  
  delay(1000);
  
  digitalWrite(buzzerPin, LOW);
  Serial.println("Buzzer Off");
  
  delay(1000);
}
