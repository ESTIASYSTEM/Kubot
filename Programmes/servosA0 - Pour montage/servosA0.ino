#include <Servo.h>

//                    --------------- 
//          SR pin 1 |     O   O     |  SL pin 0
//               ----|---------------|----
// AR pin 7------ |  |               |  |  ------  AL pin 6
//         ------ |  |               |  |  ------
//               ----|               |----
//       YR pin 3==> |               | <== YL  pin 2
//                    --------------- 
//                       ||     ||
//       RR pin 5==>   -----   ------  <== RL pin 4
//                    |-----   ------|

  Servo SR;
  Servo SL;
  Servo AR;
  Servo AL;
  Servo YR;
  Servo YL;
  Servo RR;
  Servo RL;

void setup() {
 SR.attach(7);
 SL.attach(6);
 AR.attach(13);
 AL.attach(12);
 YR.attach(3);
 YL.attach(2);
 RR.attach(5);
 RL.attach(4);
}

void loop() {
  SR.write(180/2);
  SL.write(180/2);
  AR.write(180/2);
  AL.write(180/2);
  YR.write(180/2);
  YL.write(180/2);
  RR.write(180/2);
  RL.write(180/2);
}
