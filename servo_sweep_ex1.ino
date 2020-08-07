/* The following is a quick sketch to establish control of the servo and to test
 *  a sweeping movement both in 90 degree increments and 45 degree increments over
 *  a 180 degree range.
 *  Greymatter66 - Aug 7th 2020
 */
 
#include<Servo.h>         //Include Servo library.
Servo servo1;             //Initilize a servo object;
int initial_pos = 0;      //Declare a variable for the initial position of the swing arm.

void setup() 
{
servo1.attach(9); //Use PWM pin 9 as the data pin.
}

void loop() 
{
  //Create a for loop to cycle through various positions in increments of 90 degrees.
  for(initial_pos=0; initial_pos<180; initial_pos +=90) 
  {
    servo1.write(initial_pos);
    delay(1000);
  }
  //Create a for loop for the cycle back from 180 degrees in increments of 45 degrees.
  for(initial_pos=180 ; initial_pos>1; initial_pos-=45)      
  {
    servo1.write(initial_pos);
    delay(1500);
  }
}
