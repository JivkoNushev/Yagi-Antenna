#include <math.h>
#include <Stepper.h>

// Define the number of steps per revolution for the stepper motor
const int stepsPerRevolution = 200;

// Define the pins for the stepper motor
const int motorPin1 = 8;
const int motorPin2 = 9;
const int motorPin3 = 10;
const int motorPin4 = 11;

// Define the current location and target location
const double current_lat = 40.7128; // Replace with your current latitude
const double current_lon = -74.0060; // Replace with your current longitude
const double target_lat = 37.7749; // Replace with the target latitude
const double target_lon = -122.4194; // Replace with the target longitude

// Define the step angle of our motors
const double step_angle = 1.8; // in degrees

void setup() {
  // Initialize the stepper motor with the number of steps per revolution and the motor pins
  Stepper myStepper(stepsPerRevolution, motorPin1, motorPin2, motorPin3, motorPin4);
  
  // Set the speed of the stepper motor in RPM (revolutions per minute)
  myStepper.setSpeed(10);
  
  // Calculate the bearing using the Haversine formula
  double d_lon = radians(target_lon - current_lon);
  double lat1 = radians(current_lat);
  double lat2 = radians(target_lat);
  double d_lat = lat2 - lat1;
  double y = sin(d_lon) * cos(lat2);
  double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(d_lon);
  double bearing = atan2(y, x);

  // Convert the bearing from radians to degrees
  double bearing_degrees = degrees(bearing);

  // Calculate the angle to point the antenna towards the target
  double angle_to_target = bearing_degrees - 90.0;

  // Convert the angle to steps for the motor
  int steps = angle_to_target / step_angle;

  // Rotate the stepper motor to point the antenna towards the target
  myStepper.step(steps);
}

void loop() {
  // Nothing to do here
}
