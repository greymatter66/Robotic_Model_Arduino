/* A sketch to run through a pick and place program for
 * a small robotic arm. Fixed ranges were hard coded in.
 * 
 * Sketch by greymatter66 2020 
 */
 
// Include the stepper and servo library
#include <Stepper.h> 
#include<Servo.h>                           

// Declare variables
const float STEPS_PER_REV = 32;
const float GEAR_REDUCTION = 64;
const float TOTAL_STEPS_REV = STEPS_PER_REV * GEAR_REDUCTION;
int step_num;
int grip_open = 60;
int grip_close = 0;

// Create a stepper instance for each motor and initialize it, note sequence of pins as second arg.
Stepper my_stepper_1(STEPS_PER_REV, 8,10,9,11);
Stepper my_stepper_2(STEPS_PER_REV, 4,6,5,7);
// Create a servo instance.
Servo gripper;

void setup() // Attach gripper to digital pin 2 and set initial position to zero.
{
  gripper.attach(2);
  gripper.write(grip_close);
}

void loop()
{
  //Stepper_1:Clockwise
  my_stepper_1.setSpeed(750);               
  step_num = TOTAL_STEPS_REV/4;             
  my_stepper_1.step(step_num);              
  delay(250);                              

   //Stepper_2: (Lower Arm)
  my_stepper_2.setSpeed(750);
  step_num = -TOTAL_STEPS_REV /10;       
  my_stepper_2.step(step_num);
  delay(250);

  //Gripper Open/Close (Capture Item)
  gripper.write(grip_open);
  delay(1000);
  gripper.write(grip_close);

  //Stepper_2: (Lift Arm)
  my_stepper_2.setSpeed(750);              
  step_num = TOTAL_STEPS_REV/10;            
  my_stepper_2.step(step_num);             
  delay(2500);                             

  
  //Stepper_1:Counter-Clockwise                                   
  my_stepper_1.setSpeed(750);
  step_num = - TOTAL_STEPS_REV /3;         
  my_stepper_1.step(step_num);
  delay(250);

  //Stepper_2:Clockwise (Lower Arm)
  my_stepper_2.setSpeed(750);
  step_num = -TOTAL_STEPS_REV /4;       
  my_stepper_2.step(step_num);
  delay(250);

  //Gripper Open/Close (Release Item)
  gripper.write(grip_open);
  delay(1000);
  gripper.write(grip_close);

  //Stepper_2:Counter-Clockwise (Lift Arm)
  my_stepper_2.setSpeed(750);             
  step_num = TOTAL_STEPS_REV/4;            
  my_stepper_2.step(step_num);             
  delay(250);                             

}
