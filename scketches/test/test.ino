/*
 Stepper Motor Control - one rev back and forth
 This program is for the SparkFun Easy motor driver board.
 This program drives a bipolar stepper motor.
 The motor is attached to ground plus digital pins 8 and 9 of the Arduino.
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction at a speed determined by 
 the milliseconds in the microSecDelay variable.
 Created by Bill Harper, Feb. 10 2014
 
 */
#include <Stepper.h>
int oneway;                      // counter for steps
int onerev = 6400;               // number of steps each direction (edit this 
                                 // for your particular motor)
int microSecDelay = 30;          // delay between steps and speed of the motor 
//                                    (about as fast as the system can react,
//                                    higher number = slower)
int dirPin = 6;                  // output pin for stepper motor direction
int stepPin = 7;                 // output pin for the pin used to step the motor
void setup() {                
  pinMode(dirPin, OUTPUT);       // Assign output mode to pin for direction
  pinMode(stepPin, OUTPUT);      // Assign output mode to pin for setp
  digitalWrite(dirPin, LOW);     // Initialize dir pin 
  digitalWrite(stepPin, LOW);    // Initialize step pin
  oneway = 1;
}
void loop() {
  if (oneway < onerev + 1)            // Still in first revolution?
    {
      digitalWrite(dirPin, LOW);      // Keep direction pin low
    }
  else
    {
      digitalWrite(dirPin, HIGH);    // If not in first revolution change 
//                                        direction pin to High
    }
  digitalWrite(stepPin, HIGH);       // Step motor
  delayMicroseconds(microSecDelay);  // Wait microseconds
  digitalWrite(stepPin, LOW);        // Step motor
  delayMicroseconds(microSecDelay);  // Wait microseconds
  oneway += 1;                       // Increment direction counter
  if (oneway > onerev * 2)           // If we have exceeded two revolutions
    { oneway = 1; }                  // Reset counter to start over again
  
}                                    // EOF
