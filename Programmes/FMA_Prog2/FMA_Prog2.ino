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
void setup(){
  
  //Set the servo pins
  Kubo.initialize(PIN_YL,PIN_YR,PIN_RL,PIN_RR);
  
  connectionSong(Kubo); // on joue le son de connection
  
  Kubo.home();
  delay(50);
  happySong(Kubo);
}



///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop()
{
  
  if(obstacleDetected)
  {    
    Kubo.walk(2,1300,-1); 
    Kubo.turn(2,1000,-1);   
                 
    delay(50); 
    obstacleDetector(); 
  }        
  else
  { 
    Kubo.walk(1,1000,1); 
    obstacleDetector(); 
  }           
}



///////////////////////////////////////////////////////////////////
//-- Fonction pour lire le capteur et actualiser l'état du capteur
void obstacleDetector()
{
  int distance = Kubo.getDistance();
  if(distance<15)
  {
    obstacleDetected = true;
  }
  else
  {
    obstacleDetected = false;
  }
}


void connectionSong(Kubot &k)
{
  k._tone(NOTE_Mi5,50,30);
  k._tone(NOTE_Mi6,55,25);
  k._tone(NOTE_La6,60,10);
}

void disconnectionSong(Kubot &k)
{
  k._tone(NOTE_Mi5,50,30);
  k._tone(NOTE_La6,55,25);
  k._tone(NOTE_Mi6,50,10);
}

void happySong(Kubot &k)
{
}

void superHappySong(Kubot &k)
{
}




