/*
 * Test sketch of servo in isolation.
 * Servo will be motor for gripper action.
 * Adjusting measurement of grip_open may
 * be necessary when combined with second
 * arm. 
 * greymatter66 2020
 */
#include<Servo.h>
Servo gripper;
int grip_open = 60;
int grip_closed = 0;

void setup() 
{
  gripper.attach(12);
  gripper.write(0);
  delay(1000);
}

void loop() 
{
  gripper.write(grip_open);
  delay(1000);
  gripper.write(grip_closed);
  delay(1000);
}
