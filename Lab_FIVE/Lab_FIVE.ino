#include "arduino_secrets.h"

/*

*/
#define motorPin 18 //enabling/disabling
#define motorFwd 32 //forward
#define motorRev 33 //reverse

void setup() {
  
  pinMode(motorPin, OUTPUT);
  pinMode(motorFwd, OUTPUT);
  pinMode(motorRev, OUTPUT);
  
  Serial.begin(9600);
  while(!Serial);
    
}

void loop() {
  
  Serial.println("Loop restarted");
  Serial.println("Motor On, Forward");
  digitalWrite(motorPin, HIGH);
  digitalWrite(motorFwd, HIGH);
  digitalWrite(motorRev, LOW);
  
  Serial.println("Motor is moving...");
 /* 
  
  delay(5000);
  
  Serial.println("Motor Off");
  digitalWrite(motorPin, LOW);
  
  delay(5000);
  
  Serial.println("Motor On, Reverse");
  digitalWrite(motorPin, HIGH);
  digitalWrite(motorFwd, LOW);
  digitalWrite(motorRev, HIGH);
  */
  delay(5000);
  
  Serial.println("Motor Off");
  digitalWrite(motorPin, LOW);
  delay(5000);
  
  Serial.println("Motor is still off");
}




