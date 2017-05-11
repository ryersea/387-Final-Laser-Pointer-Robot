#include <Servo.h>
Servo tilt; //creates servo object for x axis
Servo pan; // Creates servo object for y axis
int joyX = A0; // Analog pin connected to x-axis servo
int joyY = A1; // Analog pin connected to y-axis servo
int x; 
int y; // Variables to read values

void setup() {
tilt.attach(9); // Attach tilt servo on pin 9 to the servo x object
pan.attach(10); // Attach pan servo on pin 10 to the servo y object

Serial.begin(9600); //begins serial monitor

}

void loop() {
x = joyX; // Read value of x-axis (between 0 and 1023)
y = joyY; // Read value of y-axis (between 0 and 1023)
x = map(analogRead(joyX), 0, 1023, 900, 2100); // Scale it to use with servo between 900 to 2100 microseconds
Serial.print("Read x: ");
Serial.println(x);

y = map(analogRead(joyY), 0, 1023, 900, 2100); 
Serial.print("Read y: ");
Serial.println(y);
tilt.write(x); // Set servo position according to scaled value
pan.write(y); // sets second servo position according to a scaled value
delay(15); // Wait for servos to get to new position
}
