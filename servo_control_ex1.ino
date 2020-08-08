/* The following is a quick sketch to establish control of the servo and to test
 *  control by joystick in a clockwise and anti-colockwise direction and over a 180 
 *  degree range.
 *  Greymatter66 - Aug 8th 2020
 */
#include<Servo.h>                //Include Servo library.

Servo my_servo;                  //Initialize servo object.

int joyx= A0;                    //X-axis of joystick read in on Analog 0.

int joyval;                      //Variable to store value read in on A0.

void setup()
{
  my_servo.attach(3);           //Attach the servo object to pin 3.
}

void loop() 
{
  joyval=analogRead(joyx);                //Read in the value from joystick.
  joyval=map(joyval, 0, 1023, 0, 180);    //Map the value range from analog in to a range of 0-180 degrees.
  my_servo.write(joyval);                 //Write the value to the servo to create movement.
}
