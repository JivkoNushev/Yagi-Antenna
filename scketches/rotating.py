import math

# Define our current location and target location
current_lat = 40.7128
current_lon = -74.0060

target_lat = 37.7749
target_lon = -122.4194

# Define the step angle of our motors
step_angle = 1.8 # in degrees

# Calculate the bearing using the Haversine formula
d_lon = math.radians(target_lon - current_lon)
lat1 = math.radians(current_lat)
lat2 = math.radians(target_lat)
d_lat = lat2 - lat1
y = math.sin(d_lon) * math.cos(lat2)
x = math.cos(lat1) * math.sin(lat2) - math.sin(lat1) * math.cos(lat2) * math.cos(d_lon)
bearing = math.atan2(y, x)

# Convert the bearing from radians to degrees
bearing_degrees = math.degrees(bearing)

# Calculate the angle to point the antenna towards the target
angle_to_target = bearing_degrees - 90.0

# Convert the angle to steps for the motor
steps = angle_to_target / step_angle

# Print the results
print("Bearing:", bearing_degrees, "degrees")
print("Angle to target:", angle_to_target, "degrees")
print("Steps to target:", steps)
