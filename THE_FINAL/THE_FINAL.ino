#include "arduino_secrets.h"

/*

*/
#define rainPin 5     //DIGITAL INPUT Pin to read rain sensor
#define ledPin 13     //DIGITAL OUTPUT Pin to enable LED
#define buzzerPin 14  //DIGITAL OUTPUT Pin to enable buzzer
#define motorPin 18   //DIGITAL OUTPUT Pin to enable/disable Motor
#define motorFwd 32   //DIGITAL OUTPUT Pin to move motor forward
#define motorRev 33   //DIGITAL OUTPUT Pin to move motor in reverse
#define lightPin 34   //ANALOG INPUT Pin to read light sensor

bool rainState = HIGH;            //When the module detects rain, the digital output goes LOW
bool rainState_previous = HIGH;   //Previous state of rain sensor, used to detect change of state
int lightValue = 0;               //Value from Analog to Digital Converter (ADC) connected to the Photoresistor
int lightValue_previous = 0;      //Previous value of light sensor, used to detect change of state
int lightThreshold = 500;         //Threshold ADC value to detect night time
int cycleCount = 0;               //Counter to go through motor control once with either rain or light state change

void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(motorFwd, OUTPUT);
  pinMode(motorRev, OUTPUT);
  pinMode(rainPin, OUTPUT);
  
  Serial.begin(9600);
  while(!Serial);
 
}

void loop() {
  
  //Read light value from ADC
  lightValue_previous = lightValue;
  lightValue = analogRead(lightPin);
  
  //Check for rain
  rainState_previous = rainState;
  rainState = digitalRead(rainPin);
  
  //Execute code upon state change
  if ((rainState_previous != rainState)
    || (lightValue_previous >= lightThreshold && lightValue < lightThreshold)
    || (lightValue_previous < lightThreshold && lightValue >= lightThreshold)) {
    
    // Print sensor values
    Serial.println();
    Serial.println("Printing Sensor Values...");
    
    Serial.println("Light Sensor Value: ");
    Serial.println(lightValue);
    
    if (lightValue < lightThreshold){
      Serial.println("Night time detected");
      cycleCount++;
    } else {
      Serial.println("Day time detected");
    }
    
    if (!rainState){
      Serial.println("Rain detected");
      cycleCount++;
    } else {
      Serial.println("No rain detected");
    }
    
    //Motor control based on rain state and light intensity 
    // Run code if rain detected or light value is below day time threshold
    if ((!rainState || lightValue < lightThreshold) && cycleCount == 1) {
      
      // Print to serial monitor 
      Serial.println("Bring in the line!");
      
      // Turn off LED
      digitalWrite(ledPin, LOW);
      
      // Turn on buzzer
      digitalWrite(buzzerPin, HIGH);
      
      //Reverse motor to pull in laundry line for 5 seconds
      Serial.println("Motor On, Reverse");
      digitalWrite(motorPin, HIGH);
      digitalWrite(motorFwd, LOW);
      digitalWrite(motorRev, HIGH);
      
      delay(5000);
      
      // Turn off buzzer
      digitalWrite(buzzerPin, LOW);
      
      // Turn off motor
      Serial.println("Motor off");
      digitalWrite(motorPin, LOW);
      
    }
    
    // Else when rain is not detected and light value is above day time threshold 
    else if (rainState && lightValue >= lightThreshold) {
      
      cycleCount = 0;
      
      // Print to serial monitor
      Serial.println("Taking out the line!");
      
      // Turn on LED
      digitalWrite(ledPin, HIGH);
      
      // Forward motor to take out laundry line for 5 seconds
      Serial.println("Motor On, Forward");
      digitalWrite(motorPin, HIGH);
      digitalWrite(motorFwd, HIGH);
      digitalWrite(motorRev, LOW);
      
      delay(5000);
      
      //Turn off motor
      Serial.println("Motor off");
      digitalWrite(motorPin, LOW);
      
    }
  }   
}