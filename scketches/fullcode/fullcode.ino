#include <Stepper.h>

// JOYSTICK:
#define VRX_PIN A0 // Arduino pin connected to VRX pin
#define VRY_PIN A1 // Arduino pin connected to VRY pin
int xValue;        // variable to store the value coming from the VRx
int yValue;        // variable to store the value coming from the VRyg

// STEPPER:
int microSecDelay1 = 300, microSecDelay2 = 700;
int onerev = 6400; // our motor is 200 steps (1.8 degrees per step)
int oneway1, oneway2; // used to keep track of how much the motor has turned
int dirPin1 = 5, stepPin1 = 7; // motor1
int dirPin2 = 3, stepPin2 = 4; // motor2

// RELAY:
int RelayPin = 6;
bool RelayOn = false;


void setup()
{
    // STEPPER:
    pinMode(dirPin1, OUTPUT);
    pinMode(stepPin1, OUTPUT);
    digitalWrite(dirPin1, LOW);
    digitalWrite(stepPin1, LOW);
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
    // Serial.print("x = ");
    // Serial.print(xValue);
    // Serial.print(", y = ");
    // Serial.println(yValue);

    // TODO: https://howtomechatronics.com/tutorials/arduino/stepper-motors-and-arduino-the-ultimate-guide/
        // HARDWARE:
        // -connect SLEEP and RESET pins so they are disabled
        // ~adjust potentiometer on driver for the current limit so it doesn't overheat

    // SOFTWARE:
    // ~use the library Stepper.h
    
    if (xValue > 600)
    {
        digitalWrite(dirPin1, LOW);
        digitalWrite(stepPin1, HIGH);     // Step motor
        delayMicroseconds(microSecDelay1); // Wait microseconds
        digitalWrite(stepPin1, LOW);      // Step motor
        delayMicroseconds(microSecDelay1); // Wait microseconds
    }
    else if (xValue < 300)
    {
        digitalWrite(dirPin1, HIGH);
        digitalWrite(stepPin1, HIGH);
        delayMicroseconds(microSecDelay1);
        digitalWrite(stepPin1, LOW);
        delayMicroseconds(microSecDelay1);
    }

    if (yValue > 600)
    {
        digitalWrite(dirPin2, LOW);
        digitalWrite(stepPin2, HIGH);
        delayMicroseconds(microSecDelay2);
        digitalWrite(stepPin2, LOW);
        delayMicroseconds(microSecDelay2);
    }
    else if (yValue < 300)
    {
        digitalWrite(dirPin2, HIGH);
        digitalWrite(stepPin2, HIGH);
        delayMicroseconds(microSecDelay2);
        digitalWrite(stepPin2, LOW);
        delayMicroseconds(microSecDelay2);
    }
}