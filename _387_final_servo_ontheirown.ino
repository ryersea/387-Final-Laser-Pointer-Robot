
#include <Servo.h> 

Servo motor; //first servo motor
Servo motor1; // second servo motor

int state = 0;
int theta = 1;

void setup() { 
  Serial.begin(9600);
  motor.attach(10); //attaches to the second servo motor that moves in the y direction
  motor1.attach(9); //attaches to the first servo motor that moves in the x direction

 } 
 
void loop() { 

// Checks the position and changes states
 if (theta <= 1)
   state = 0;
    
 if (theta >= 180)
  state = 1;

  // Checks the state and moves the position of the servo motor
 if (state == 0)
  theta = theta+1;
    
 if (state == 1)
      theta = theta-1;

  // Moves the motor
  motor.write(theta);  //of the first servo motor
  delay(15);
  motor1.write(theta); // of the second servo motor

  Serial.println(theta); 


}
