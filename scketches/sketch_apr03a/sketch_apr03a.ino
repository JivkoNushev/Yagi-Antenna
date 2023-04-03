#include <Stepper.h>


//JOYSTICK:
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

//STEPPER:
int oneway;
int onerev = 6400;
int microSecDelay = 3000;
int dirPin = 5;
int stepPin = 7;

//RELAY:
int RelayPin = 6;


void setup() {
    Serial.begin(9600);
//STEPPER:
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, LOW);
    oneway = 1;

//RELAY:
    pinMode(RelayPin, OUTPUT);
    digitalWrite(RelayPin, HIGH);
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

    if (oneway < onerev + 1)            // Still in first revolution?
    {
      digitalWrite(dirPin, LOW);      // Keep direction pin low
    }
    else
    {
      digitalWrite(dirPin, HIGH);    // If not in first revolution change 
    }

    digitalWrite(stepPin, HIGH);       // Step motor
    delayMicroseconds(microSecDelay);  // Wait microseconds
    digitalWrite(stepPin, LOW);        // Step motor
    delayMicroseconds(microSecDelay);  // Wait microseconds
    
    oneway += 1;                       // Increment direction counter
    if (oneway > onerev * 2)           // If we have exceeded two revolutions
        { oneway = 1; }                  // Reset counter to start over again
}
