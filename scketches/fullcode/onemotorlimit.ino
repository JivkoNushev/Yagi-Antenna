#include <Stepper.h>

// JOYSTICK:
#define VRX_PIN A0 // Arduino pin connected to VRX pin
#define VRY_PIN A1 // Arduino pin connected to VRY pin
int xValue;        // variable to store the value coming from the VRx
int yValue;        // variable to store the value coming from the VRyg

// STEPPER:
int microSecDelay = 700;
int oneway1, oneway2; // used to keep track of how much the motor has turned
int steps1, steps2;
int dirPin1 = 5, stepPin1 = 7; // motor1
int dirPin2 = 3, stepPin2 = 4; // motor2

// RELAY:
int RelayPin = 6;
bool RelayOn = false;


void setup()
{
    Serial.begin(9600);
    // STEPPER:
    pinMode(dirPin1, OUTPUT);
    pinMode(stepPin1, OUTPUT);
    digitalWrite(dirPin1, LOW);
    digitalWrite(stepPin1, LOW);
    steps1 = 0
    oneway1 = 1;

    pinMode(dirPin2, OUTPUT);
    pinMode(stepPin2, OUTPUT);
    digitalWrite(dirPin2, LOW);
    digitalWrite(stepPin2, LOW);
    oneway2 = 1;

    // RELAY:
    pinMode(RelayPin, OUTPUT);
    digitalWrite(RelayPin, HIGH);
}

void loop()
{
    // read analog X and Y analog values
    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);

    // print data to Serial Monitor on Arduino IDE
    Serial.print("x = ");
    Serial.print(xValue);
    Serial.print(", y = ");
    Serial.println(yValue);

    if(xValue > 600){
        steps1++;
        if(steps1>=200){
          steps1 = 200
        }
        else{
          digitalWrite(dirPin1, LOW);
          digitalWrite(stepPin1, HIGH);       // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
          digitalWrite(stepPin1, LOW);        // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
        }
        
    }
    else if(xValue<300){
        steps1--;
        if(steps1<=0){
          steps1 = 0
        }
        else{
          digitalWrite(dirPin1, HIGH);
          digitalWrite(stepPin1, HIGH);       // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
          digitalWrite(stepPin1, LOW);        // Step motor
          delayMicroseconds(microSecDelay);  // Wait microseconds
        }
    }
}