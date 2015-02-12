//
// RemoteControlRobot
//
// Control the robot using an IR TV remote control.
// 
// The analog sensor is connected to Port S0
//
//  NOTES: 
//      - Ports S0-S5 are analog input pins
//      - S0 is identical to Arduino A0 and so on (S5=A5)
//      - To use these ports as Digital pins add 14
//      - Use this example with the Multiplo IR 38 KHz sensor and a 
//        standard RC5 remote control
//

#include <IRremote.h>
#include <DCMotor.h>

#define SPEED 50

IRrecv irReceiver(A0); //S0 input

DCMotor motor0(M0_EN, M0_D0, M0_D1);
DCMotor motor1(M1_EN, M1_D0, M1_D1);

void setup()
{
  motor1.setClockwise(false);
}

void loop()
{
   int code = irReceiver.getIRRemoteCode();
   if (code == 2)
   {
      motor0.setSpeed(SPEED);
      motor1.setSpeed(SPEED);
   }
   else if (code == 8)
   {
      motor0.setSpeed(-SPEED);
      motor1.setSpeed(-SPEED);
   }
   else if (code == 6)
   {
      motor0.setSpeed(-SPEED);
      motor1.setSpeed(SPEED);
   }
   else if (code == 4)
   {
      motor0.setSpeed(SPEED);
      motor1.setSpeed(-SPEED);
   }
   else if (code == 5)
   {
      motor0.setSpeed(0);
      motor1.setSpeed(0);
   }
}
