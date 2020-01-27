#include "Kubot.hpp"
#include "Kubot_Sounds.hpp"
#include <Servo.h>
#include <Oscillator.h>
#include <US.h>

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

int tempo=130;
bool obstacleDetected = false;
int i = 0;

Kubot Kubo;


///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////

void setup()
{
  // On initialise notre Kubot nommé Kubo
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

  i++;
  if(i>6){
    thunderstruck(Kubo);
    i=0;
  }

}

///////////////////////////////////////////////////////////////////
//-- Fonctions---------------------------------------------------//
///////////////////////////////////////////////////////////////////

int T(float nbTemps){             //Transforme des temps en millisecondes
  float duree;                    //tempo = nb de pulsations par minute
  duree = nbTemps*60000/tempo;    //durée = nbTemps * 1min/tempo
  return duree;                   //(1min = 60 000ms)
}

void thunderstruck(Kubot &k){
  tempo = 130;

  k._tone(NOTE_Si5,T(0.25));

  //4-0-7-0
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25)); k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25)); k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25)); k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  //
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  //5-0-8-0

  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  //
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  //4-0-7-0
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  //5-0-8-0
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Sol6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  //12-0-10-0-9-0-10-0-9-0-7-0-9-0-5-0
  k._tone(NOTE_Si6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  //
  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  //12-0-10-0-9-0-10-0-9-0-7-0-9-0-5-0
  k._tone(NOTE_Si6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  //12-0-10-0-9-0-10-0-9-0-7-0-9-0-5-0
   k._tone(NOTE_Si6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  //12-0-10-0-9-0-10-0-9-0-7-0-9-0-5-0
  k._tone(NOTE_Si6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Sold6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

  k._tone(NOTE_Fad6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));
  k._tone(NOTE_Mi6,T(0.25));  k._tone(NOTE_Si5,T(0.25));  k._tone(NOTE_Red6,T(0.25));  k._tone(NOTE_Si5,T(0.25));

}
