#include "Kubot.hpp"
#include "Kubot_Sounds.hpp"

//               --------------- 
//              |     O   O     |
//              |---------------|
//  YR pin 3==> |               | <== YL  pin 2
//               --------------- 
//                  ||     ||
//  RR pin 5==>   -----   ------  <== RL pin 
//               |-----   ------|


#define PIN_YR 3
#define PIN_YL 2
#define PIN_RR 5
#define PIN_RL 4

#define PIN_RA 7
#define PIN_LA 6

Kubot Kubo;

Oscillator rightArm;
Oscillator leftArm;
///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////

//-- Paramettres de mobement
int T=1000;              //Durée initial d'un movement
int moveId=0;            //Nombre de mouvements
int moveSize=15;         //Configure la hauteur de certains movements
//---------------------------------------------------------
bool obstacleDetected = false;



///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////

void setup()
{
  
  //Set the servo pins
  Kubo.initialize(PIN_YL,PIN_YR,PIN_RL,PIN_RR);

  // Configuration des bras
  rightArm.attach(PIN_RA);
  leftArm.attach(PIN_LA);
  
//  connectionSong(Kubo); // on joue le son de connection

  rightArm.SetPosition(90);
  leftArm.SetPosition(90);
  
  Kubo.home();
  delay(50);
  
}



///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop()
{
  Kubo.home();
  rightArm.SetPosition(90);
  leftArm.SetPosition(90);
/*
  delay(15);

  int pos[] = {90,90,90,90};
  while(true)
  {
    Kubo.moveServos(100,pos);
  }
  */
  Kubo.glissando(NOTE_Do0,NOTE_Do7,1000);
  Kubo.swing(1, 1400, 50);
  Kubo.home();

  rightArm.SetPosition(180);
  leftArm.SetPosition(180);
  
  Kubo._tone(NOTE_Do7,1000);
  Kubo.bend();
  Kubo.home();

  rightArm.SetPosition(90);
  leftArm.SetPosition(90);
  
  Kubo.glissando(NOTE_Do0,NOTE_Do7,1000);
  Kubo.shakeLeg();
  Kubo.home();

  rightArm.SetPosition(0);
  leftArm.SetPosition(0);

  Kubo.glissando(NOTE_Do0,NOTE_Do7,1000);
  Kubo.updown();
  Kubo.home();

  rightArm.SetPosition(90);
  leftArm.SetPosition(90);
  
  Kubo.glissando(NOTE_Do7,NOTE_Do0,1000);
  Kubo.tiptoeSwing();
  Kubo.home();

  rightArm.SetPosition(180);
  leftArm.SetPosition(180);
  
  Kubo.glissando(NOTE_Do0,NOTE_Do7,1000);
  Kubo.moonwalker();
  Kubo.home();

  rightArm.SetPosition(120);
  leftArm.SetPosition(120);

  
  Kubo.jitter();
  Kubo.home();
  
}


