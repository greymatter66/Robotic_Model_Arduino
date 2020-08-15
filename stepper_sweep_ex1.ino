/* A basic sketch to test each stepper motor for function.
 * Initally the test is just rotation in a 180 degree clockwise 
 * and counter-clockwise direction. The stepper in use with this 
 * sketch is the 28BYJ-48 unipolar stepper and the steps per 
 * revolution and gear reduction are specific to this motor.
 * The motor driver in use is the ULN2003 driver module.
 * Sketch by greymatter66 2020 modeled on sketch by
 * DroneBot Workshop 2018 https://dronebotworkshop.com
 */
// Include the stepper library
#include <Stepper.h>                            

// Declare variables
const float STEPS_PER_REV = 32;
const float GEAR_REDUCTION = 64;
const float TOTAL_STEPS_REV = STEPS_PER_REV * GEAR_REDUCTION;
int step_num;

// Create a stepper instance and initialize it, note sequence of pins as second arg.
Stepper my_stepper(STEPS_PER_REV, 8,10,9,11);

void setup() 
{
  // Nothing needed in setup()
}

void loop() {
  my_stepper.setSpeed(750);              //Stepper rotation in clockwise direction.
  step_num = TOTAL_STEPS_REV/2;          //Sets range to 180 degrees.
  my_stepper.step(step_num);             //Instruction to begin steps.
  delay(2000);                           //Two second delay before next code segment.

                                         //Stepper rotation in a counter-clockwise direction.
  my_stepper.setSpeed(750);
  step_num = - TOTAL_STEPS_REV /2;       //Note minus sign for reverse direction.
  my_stepper.step(step_num);
  delay(2000);

}
