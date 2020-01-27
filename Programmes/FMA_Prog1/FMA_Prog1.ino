#include <Kubot.hpp>
#include "Kubot_Sounds.hpp"

//               ---------------
//              |     O   O     |
//              |---------------|
//  YR pin 3==> |               | <== YL  pin 2
//               ---------------
//                  ||     ||
//  RR pin 5==>   -----   ------  <== RL pin 4
//               |-----   ------|



#define PIN_YR 3
#define PIN_YL 2
#define PIN_RR 5
#define PIN_RL 4

Kubot Kubo;


///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup()
{

  // On initialise notre Kubot nomé Kubo
  Kubo.initialize(PIN_YL,PIN_YR,PIN_RL,PIN_RR);

  Kubo.home();
  delay(250);
}



///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop()
{
  Kubo.tiptoeSwing(1,500,20);
  Kubo.home();
  delay(250);
  Kubo.tiptoeSwing(1,500,-20);
  Kubo.home();
  delay(250);
}



