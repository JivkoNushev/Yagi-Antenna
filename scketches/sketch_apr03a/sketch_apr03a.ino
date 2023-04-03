#include <Stepper.h>


//JOYSTICK:
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
int xValue; // variable to store the value coming from the VRx
int yValue; // variable to store the value coming from the VRy

//STEPPER:
int oneway;
int onerev = 6400;
int microSecDelay = 300;
int dirPin = 5;
int stepPin = 7;

//RELAY:
int RelayPin = 6;
int RelayOn = 0;

void setup() {
//STEPPER:
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, LOW);
    oneway = 1;

//RELAY:
    pinMode(RelayPin, OUTPUT);
    digitalWrite(RelayPin, LOW);
}

void loop() {
    // read analog X and Y analog values
    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);

    // print data to Serial Monitor on Arduino IDE
    Serial.print("x = ");
    Serial.print(xValue);
    Serial.print(", y = ");
    Serial.println(yValue);

    if(xValue > 510 || xValue < 490){

      if(RelayOn == 0)
      {
        digitalWrite(RelayPin, HIGH);
        RelayOn = 1;
      }
      
      if(xValue > 510){        
          digitalWrite(dirPin, LOW);
          digitalWrite(stepPin, HIGH);       // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
          digitalWrite(stepPin, LOW);        // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
          
      }
      else if(xValue<490){
          digitalWrite(dirPin, HIGH);
          digitalWrite(stepPin, HIGH);       // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
          digitalWrite(stepPin, LOW);        // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
      }       
    }
    else
    {
      if(RelayOn == 1)
      {
        digitalWrite(RelayPin, LOW);
        RelayOn = 0;
      }
    }
    
    
    
}
