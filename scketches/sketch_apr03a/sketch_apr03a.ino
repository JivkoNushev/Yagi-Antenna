#include <Stepper.h>

// JOYSTICK:
#define VRX_PIN A0 // Arduino pin connected to VRX pin
#define VRY_PIN A1 // Arduino pin connected to VRY pin
int xValue;        // variable to store the value coming from the VRx
int yValue;        // variable to store the value coming from the VRyg

// STEPPER:
int microSecDelay = 300;
int onerev = 6400;
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
    digitalWrite(RelayPin, LOW);
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

    if (xValue > 510 || xValue < 490 || yValue > 510 || yValue < 490)
    {
        if (!RelayOn)
        {
            digitalWrite(RelayPin, HIGH);
            RelayOn = true;
        }

        if (xValue > 510)
        {
            digitalWrite(dirPin1, LOW);
            digitalWrite(stepPin1, HIGH);     // Step motor
            delayMicroseconds(microSecDelay); // Wait microseconds
            digitalWrite(stepPin1, LOW);      // Step motor
            delayMicroseconds(microSecDelay); // Wait microseconds
        }
        else if (xValue < 490)
        {
            digitalWrite(dirPin1, HIGH);
            digitalWrite(stepPin1, HIGH);
            delayMicroseconds(microSecDelay);
            digitalWrite(stepPin1, LOW);
            delayMicroseconds(microSecDelay);
        }

        if (yValue > 510)
        {
            digitalWrite(dirPin2, LOW);
            digitalWrite(stepPin2, HIGH);
            delayMicroseconds(microSecDelay);
            digitalWrite(stepPin2, LOW);
            delayMicroseconds(microSecDelay);
        }
        else if (yValue < 490)
        {
            digitalWrite(dirPin2, HIGH);
            digitalWrite(stepPin2, HIGH);
            delayMicroseconds(microSecDelay);
            digitalWrite(stepPin2, LOW);
            delayMicroseconds(microSecDelay);
        }
    }
    else
    {
        if (RelayOn)
        {
            digitalWrite(RelayPin, LOW);
            RelayOn = false;
        }
    }
}