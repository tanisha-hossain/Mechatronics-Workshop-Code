#include "arduino_secrets.h"

#include <Arduino.h> 
/*

*/
#define motorPin 18 //enabling/disabling
#define motorFwd 32 //forward
#define motorRev 33 //reverse

const int frequency = 1000;
const int PWMChannel = 0;
const int resolution = 8;

void setup() {
  
  pinMode(motorPin, OUTPUT);
  pinMode(motorFwd, OUTPUT);
  pinMode(motorRev, OUTPUT);
  
  ledcSetup(PWMChannel, frequency, resolution);
  ledcAttachPin(motorPin, PWMChannel);
  
  Serial.begin(9600);
  while(!Serial);
    
}

void loop() {
  
  Serial.println("Loop restarted");
  Serial.println("Motor On, Forward 100%");
  ledcWrite(PWMChannel, 255);
  digitalWrite(motorFwd, HIGH);
  digitalWrite(motorRev, LOW);
  
  Serial.println("Motor is moving...");
 
  
  delay(5000);
  
  Serial.println("Motor On, Forward 50%");
  ledcWrite(PWMChannel, 128);
  digitalWrite(motorFwd, HIGH);
  digitalWrite(motorRev, LOW);
  
  Serial.println("Motor Off");
  digitalWrite(motorPin, LOW);
  
  delay(5000);
  
  Serial.println("Motor On, Reverse 100%");
  ledcWrite(PWMChannel, 255);
  /*for (int foo = 0; foo<=255; foo++){
    ledcWrite(PWMChannel, foo);
    Serial.println("The duty cycle is: "+foo);
    delay(1000);
    */
    
  digitalWrite(motorFwd, LOW);
  digitalWrite(motorRev, HIGH);
  
  delay(5000);
  
   Serial.println("Motor On, Reverse 50%");
  ledcWrite(PWMChannel, 128);
  digitalWrite(motorFwd, LOW);
  digitalWrite(motorRev, HIGH);
  
  delay(5000);
  
  Serial.println("Motor Off");
  ledcWrite(PWMChannel, 0);
  
  delay(5000);
  
  Serial.println("Motor is still off");
  
}




