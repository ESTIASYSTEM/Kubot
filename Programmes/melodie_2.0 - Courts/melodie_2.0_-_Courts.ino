#include <Kubot.hpp>
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

int i=0;
int tempo=200;
bool obstacleDetected = false;

Kubot Kubo;


///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////

void setup()
{
  // On initialise notre Kubot nomé Kubo
  Kubo.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR);
  randomSeed(analogRead(A0));
  i=random(3);
  connectionSong(Kubo); // on joue le son de connection

  Kubo.home();
  delay(50);
  //happySong(Kubo);
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////

void loop()
{   
 if(obstacleDetected){// 
  happySong(Kubo);   
  delay(1000); 

  if(i==0){
    sevenNationArmy(Kubo); 
  }else if(i==1) {
    GOT(Kubo);
  }else if(i==2) {
    thunderstruck(Kubo);
  }
  delay(500);
  disconnectionSong(Kubo);
  obstacleDetected = false;
  i++;
  if(i==3){
    i=0;
  }
  }else{ 
           if( Kubo.getDistance() < 2 )
           obstacleDetected = true;
           else
           obstacleDetected = false;  
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

void sevenNationArmy(Kubot &k){
  tempo = 124;
  
  k._tone(NOTE_Mi4,T(1.5));
  k._tone(NOTE_Mi4,T(0.5));
  k._tone(NOTE_Sol4,T(0.5),T(0.25));
  k._tone(NOTE_Mi4,T(0.25),T(0.5));
  k._tone(NOTE_Re4,T(0.5));
  k._tone(NOTE_Do4,T(2));
  k._tone(NOTE_Si3,T(1),T(1));

  k._tone(NOTE_Mi4,T(1.5));
  k._tone(NOTE_Mi4,T(0.5));
  k._tone(NOTE_Sol4,T(0.5),T(0.25));
  k._tone(NOTE_Mi4,T(0.25),T(0.5));
  k._tone(NOTE_Re4,T(0.5));
  k._tone(NOTE_Do4,T(0.5),T(0.25));
  k._tone(NOTE_Re4,T(0.5),T(0.25));
  k._tone(NOTE_Do4,T(0.25),T(0.25));
  k._tone(NOTE_Si3,T(1),T(1));

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
} 

void L_s_Theme(Kubot &k){
  tempo = 72;
  
  k._tone(NOTE_Sol5,T(0.25));  k._tone(NOTE_Mi5,T(0.25));  k._tone(NOTE_La5,T(0.25)); k._tone(NOTE_Mi5,T(0.25)); 
  k._tone(NOTE_Fad5,T(0.25));  k._tone(NOTE_Sol5,T(0.25));   k._tone(NOTE_Mi5,T(0.25)); k._tone(NOTE_Si6,T(0.25));
  k._tone(NOTE_La5,T(0.25));  k._tone(NOTE_Sol5,T(0.25));  k._tone(NOTE_Fad5,T(0.25)); k._tone(NOTE_Mi5,T(0.25));
  k._tone(NOTE_Re5,T(0.25));  k._tone(NOTE_Sol5,T(0.25));  k._tone(NOTE_Mi5,T(0.25)); k._tone(NOTE_La5,T(0.25));   
 
  k._tone(NOTE_Mi5,T(0.25));  k._tone(NOTE_Fad5,T(0.25));  k._tone(NOTE_Sol5,T(0.25)); k._tone(NOTE_Mi5,T(0.25)); 
  k._tone(NOTE_Si6,T(0.25));  k._tone(NOTE_La5,T(0.25));  k._tone(NOTE_Sol5,T(0.25));   k._tone(NOTE_Fad5,T(0.25));  
  k._tone(NOTE_Mi5,T(0.25));  k._tone(NOTE_Re5,T(0.25)); k._tone(NOTE_Mi5,T(0.25));
}

void tetris(Kubot &k){
  tempo = 180;
  
  k._tone(NOTE_La6,T(1));
   k._tone(NOTE_Mi6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_Sol6,T(0.5));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Sol6,T(0.25));
  k._tone(NOTE_Fa6,T(0.5));  k._tone(NOTE_Mi6,T(0.5));
 
  k._tone(NOTE_Re6,T(1));
  k._tone(NOTE_Re6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_La6,T(1));
  k._tone(NOTE_Sol6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));

  k._tone(NOTE_Mi6,T(1.5));
  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_Sol6,T(1));
  k._tone(NOTE_La6,T(1));

  k._tone(NOTE_Fa6,T(1));
  k._tone(NOTE_Re6,T(1));
  k._tone(NOTE_Re6,T(2),T(0.5));
  
  //
  
  k._tone(NOTE_Sol6,T(1));
  k._tone(NOTE_Lad6,T(0.5));
  k._tone(NOTE_Re7,T(1));
  k._tone(NOTE_Do7,T(0.5));  k._tone(NOTE_Lad6,T(0.5));

  k._tone(NOTE_La6,T(1.5));
  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_La6,T(1));
  k._tone(NOTE_Sol6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  
  k._tone(NOTE_Mi6,T(1));
  k._tone(NOTE_Mi6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_Sol6,T(1));
  k._tone(NOTE_La6,T(1));

  k._tone(NOTE_Fa6,T(1));
  k._tone(NOTE_Re6,T(1));
  k._tone(NOTE_Re6,T(1),T(1));/*
  
  //
  k._tone(NOTE_La6,T(1));
  k._tone(NOTE_Mi6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_Sol6,T(0.5));  k._tone(NOTE_La6,T(0.25));  k._tone(NOTE_Sol6,T(0.25));
  k._tone(NOTE_Fa6,T(0.5));  k._tone(NOTE_Mi6,T(0.5));

  k._tone(NOTE_Re6,T(1));
  k._tone(NOTE_Re6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_La6,T(1));
  k._tone(NOTE_Sol6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));

  k._tone(NOTE_Mi6,T(1.5));
  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_Sol6,T(1));
  k._tone(NOTE_La6,T(1));

  k._tone(NOTE_Fa6,T(1));
  k._tone(NOTE_Re6,T(1));
  k._tone(NOTE_Re6,T(2),T(0.5));

  //
  k._tone(NOTE_Sol6,T(1));
  k._tone(NOTE_Lad6,T(0.5));
  k._tone(NOTE_Re7,T(1));
  k._tone(NOTE_Do7,T(0.5));  k._tone(NOTE_Lad6,T(0.5));

  k._tone(NOTE_La6,T(1.5));
  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_La6,T(1));
  k._tone(NOTE_Sol6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  
  k._tone(NOTE_Mi6,T(1));
  k._tone(NOTE_Mi6,T(0.5));  k._tone(NOTE_Fa6,T(0.5));
  k._tone(NOTE_Sol6,T(1));
  k._tone(NOTE_La6,T(1));

  k._tone(NOTE_Fa6,T(1));
  k._tone(NOTE_Re6,T(1));
  k._tone(NOTE_Re6,T(1),T(1));

  //
  k._tone(NOTE_La6,T(2));
  k._tone(NOTE_Fa6,T(2));
  
  k._tone(NOTE_Sol6,T(2));
  k._tone(NOTE_Mi6,T(2));
  
  k._tone(NOTE_Fa6,T(2));
  k._tone(NOTE_Re6,T(2));
  
  k._tone(NOTE_Dod6,T(2));
  k._tone(NOTE_Mi6,T(2));

  //
  k._tone(NOTE_La6,T(2));
  k._tone(NOTE_Fa6,T(2));
  
  k._tone(NOTE_Sol6,T(2));
  k._tone(NOTE_Mi6,T(2));
  
  k._tone(NOTE_Fa6,T(1));
  k._tone(NOTE_La6,T(1));
  k._tone(NOTE_Re7,T(2));

  k._tone(NOTE_Dod7,T(4));  */
}

void marioBros(Kubot &k){
  tempo = 200;

  //1
  k._tone(NOTE_Re6,T(0.5));  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));  k._tone(NOTE_Re6,T(0.5),T(0.5));

  k._tone(NOTE_Fa6,T(0.5),T(1.5));
  k._tone(NOTE_Fa5,T(0.5),T(1.5));

  k._tone(NOTE_Lad5,T(0.5),T(1));
  k._tone(NOTE_Fa5,T(0.5),T(1));
  k._tone(NOTE_Re5,T(0.5),T(1));

  k._tone(NOTE_Sol5,T(0.5),T(0.5));
  k._tone(NOTE_La5,T(0.5),T(0.5));
  k._tone(NOTE_Sold5,T(0.5));  k._tone(NOTE_Sol5,T(0.5),T(0.5));
  
  //3
  
  k._tone(NOTE_Fa5,T(0.3),T(0.3));
  k._tone(NOTE_Re6,T(0.3),T(0.3));  k._tone(NOTE_Fa6,T(0.3),T(0.3));  k._tone(NOTE_Sol6,T(0.5),T(0.5));
  k._tone(NOTE_Red6,T(0.5));  k._tone(NOTE_Fa6,T(0.5),T(0.5));

  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));
  k._tone(NOTE_Do6,T(0.5));  k._tone(NOTE_La5,T(0.5),T(1));

  k._tone(NOTE_Lad5,T(0.5),T(1));
  k._tone(NOTE_Fa5,T(0.5),T(1));
  k._tone(NOTE_Re5,T(0.5),T(1));

  k._tone(NOTE_Sol5,T(0.5),T(0.5));
  k._tone(NOTE_La5,T(0.5),T(0.5));
  k._tone(NOTE_Sold5,T(0.5));  k._tone(NOTE_Sol5,T(0.5),T(0.5));

  //9
  k._tone(NOTE_Fa5,T(0.3),T(0.3));
  k._tone(NOTE_Re6,T(0.3),T(0.3));  k._tone(NOTE_Fa6,T(0.3),T(0.3));  k._tone(NOTE_Sol6,T(0.5),T(0.5));
  k._tone(NOTE_Red6,T(0.5));  k._tone(NOTE_Fa6,T(0.5),T(0.5));

  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));
  k._tone(NOTE_Do6,T(0.5));  k._tone(NOTE_La5,T(0.5),T(2));/*

  k._tone(NOTE_Fa6,T(0.5));k._tone(NOTE_Mi6,T(0.5));
  k._tone(NOTE_Red6,T(0.5));k._tone(NOTE_Dod6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));
  
  k._tone(NOTE_Fad5,T(0.5));k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Do6,T(0.5),T(1));

  //13
  k._tone(NOTE_Fa6,T(0.5));k._tone(NOTE_Mi6,T(0.5));
  k._tone(NOTE_Red6,T(0.5));k._tone(NOTE_Dod6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));

  k._tone(NOTE_Lad6,T(0.5),T(0.5));
  k._tone(NOTE_Lad6,T(0.5));k._tone(NOTE_Lad6,T(0.5),T(2.5));

  k._tone(NOTE_Fa6,T(0.5));k._tone(NOTE_Mi6,T(0.5));
  k._tone(NOTE_Red6,T(0.5));k._tone(NOTE_Dod6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));

  k._tone(NOTE_Fad5,T(0.5));k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Do6,T(0.5),T(1));

  k._tone(NOTE_Dod6,T(0.5),T(1));
  k._tone(NOTE_Do6,T(0.5),T(1));

  //18
  k._tone(NOTE_Lad5,T(0.5),T(4.5));

  k._tone(NOTE_Fa6,T(0.5));k._tone(NOTE_Mi6,T(0.5));
  k._tone(NOTE_Red6,T(0.5));k._tone(NOTE_Dod6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));

  k._tone(NOTE_Fad5,T(0.5));k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Do6,T(0.5),T(1));

  k._tone(NOTE_Fa6,T(0.5));k._tone(NOTE_Mi6,T(0.5));
  k._tone(NOTE_Red6,T(0.5));k._tone(NOTE_Dod6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));

  k._tone(NOTE_Lad6,T(0.5),T(0.5));
  k._tone(NOTE_Lad6,T(0.5));k._tone(NOTE_Lad6,T(0.5),T(2.5));

  //23
  k._tone(NOTE_Fa6,T(0.5));k._tone(NOTE_Mi6,T(0.5));
  k._tone(NOTE_Red6,T(0.5));k._tone(NOTE_Dod6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));

  k._tone(NOTE_Fad5,T(0.5));k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Do6,T(0.5),T(1));

  k._tone(NOTE_Dod6,T(0.5),T(1));
  k._tone(NOTE_Do6,T(0.5),T(1));

  k._tone(NOTE_Lad5,T(0.5),T(4.5));

  k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Do6,T(0.5),T(0.5));

  //28
  k._tone(NOTE_Re6,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Sol5,T(0.5));
  k._tone(NOTE_Fa5,T(0.5),T(1.5));

  k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Do6,T(0.5));k._tone(NOTE_Re6,T(0.5),T(4));

  k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));k._tone(NOTE_Do6,T(0.5),T(0.5));

  k._tone(NOTE_Re6,T(0.5));k._tone(NOTE_Lad5,T(0.5),T(0.5));
  k._tone(NOTE_Sol5,T(0.5));
  k._tone(NOTE_Fa5,T(0.5),T(1.5));

  k._tone(NOTE_Re6,T(0.5));  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));  k._tone(NOTE_Re6,T(0.5),T(0.5));

  //34
  k._tone(NOTE_Fa6,T(0.5),T(1.5));
  k._tone(NOTE_Fa5,T(0.5),T(1.5));

  k._tone(NOTE_Lad5,T(0.5),T(1));
  k._tone(NOTE_Fa5,T(0.5),T(1));
  k._tone(NOTE_Re5,T(0.5),T(1));

  k._tone(NOTE_Sol5,T(0.5),T(0.5));
  k._tone(NOTE_La5,T(0.5),T(0.5));
  k._tone(NOTE_Sold5,T(0.5));  k._tone(NOTE_Sol5,T(0.5),T(0.5));
  
  k._tone(NOTE_Fa5,T(0.3),T(0.3));
  k._tone(NOTE_Re6,T(0.3),T(0.3));  k._tone(NOTE_Fa6,T(0.3),T(0.3));  k._tone(NOTE_Sol6,T(0.5),T(0.5));
  k._tone(NOTE_Red6,T(0.5));  k._tone(NOTE_Fa6,T(0.5),T(0.5));

  //39
  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));
  k._tone(NOTE_Do6,T(0.5));  k._tone(NOTE_La5,T(0.5),T(1));

  k._tone(NOTE_Lad5,T(0.5),T(1));
  k._tone(NOTE_Fa5,T(0.5),T(1));
  k._tone(NOTE_Re5,T(0.5),T(1));

  k._tone(NOTE_Sol5,T(0.5),T(0.5));
  k._tone(NOTE_La5,T(0.5),T(0.5));
  k._tone(NOTE_Sold5,T(0.5));  k._tone(NOTE_Sol5,T(0.5),T(0.5));

  k._tone(NOTE_Fa5,T(0.3),T(0.3));
  k._tone(NOTE_Re6,T(0.3),T(0.3));  k._tone(NOTE_Fa6,T(0.3),T(0.3));  k._tone(NOTE_Sol6,T(0.5),T(0.5));
  k._tone(NOTE_Red6,T(0.5));  k._tone(NOTE_Fa6,T(0.5),T(0.5));

  k._tone(NOTE_Re6,T(0.5),T(0.5));
  k._tone(NOTE_Lad5,T(0.5));
  k._tone(NOTE_Do6,T(0.5));  k._tone(NOTE_La5,T(0.5),T(2));*/
}

void GOT(Kubot &k){
  tempo = 90;

  //mélodie
  k._tone(NOTE_Sol5,T(1.5));
  k._tone(NOTE_Do5,T(1.25),T(0.25));

  k._tone(NOTE_Red5,T(0.25));k._tone(NOTE_Fa5,T(0.25));k._tone(NOTE_Sol5,T(1));
  k._tone(NOTE_Do5,T(0.75),T(0.25));
  k._tone(NOTE_Red5,T(0.25));k._tone(NOTE_Fa5,T(0.25));
  
  k._tone(NOTE_Re5,T(0.5));     //T(3),T(3))
  //basses
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));
  
  k._tone(NOTE_Sol2,T(0.5));
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));
  
  k._tone(NOTE_Sol2,T(0.5));
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));
  
  k._tone(NOTE_Sol2,T(0.5));
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));
  
  //mélodie
  
  k._tone(NOTE_Fa5,T(1.5));
  k._tone(NOTE_Lad4,T(1.25),T(0.25));

  k._tone(NOTE_Red5,T(0.25));k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Fa5,T(1));
  k._tone(NOTE_Lad4,T(1));
  k._tone(NOTE_Red5,T(0.25));k._tone(NOTE_Re5,T(0.25));
  
  k._tone(NOTE_Do5,T(0.5));

  //basses
  k._tone(NOTE_Sold2,T(0.25));k._tone(NOTE_Lad2,T(0.25));k._tone(NOTE_Do3,T(0.5));
  
  k._tone(NOTE_Fa2,T(0.5));
  k._tone(NOTE_Sold2,T(0.25));k._tone(NOTE_Lad2,T(0.25));k._tone(NOTE_Do3,T(0.5));
  
  k._tone(NOTE_Fa2,T(0.5));
  k._tone(NOTE_Sold2,T(0.25));k._tone(NOTE_Lad2,T(0.25));k._tone(NOTE_Do3,T(0.5));
  
  k._tone(NOTE_Fa2,T(0.5));
  k._tone(NOTE_Sold2,T(0.25));k._tone(NOTE_Lad2,T(0.25));k._tone(NOTE_Do3,T(0.5));
/*
  //mélodie
  k._tone(NOTE_Sol5,T(1.5));
  k._tone(NOTE_Do5,T(1.25),T(0.25));

  k._tone(NOTE_Red5,T(0.25));k._tone(NOTE_Fa5,T(0.25));k._tone(NOTE_Sol5,T(1));
  k._tone(NOTE_Do5,T(0.75),T(0.25));
  k._tone(NOTE_Red5,T(0.25));k._tone(NOTE_Fa5,T(0.25));
  
  k._tone(NOTE_Re5,T(0.5));     //T(3),T(3))
  //basses
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));
  
  k._tone(NOTE_Sol2,T(0.5));
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));
  
  k._tone(NOTE_Sol2,T(0.5));
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));
  
  k._tone(NOTE_Sol2,T(0.5));
  k._tone(NOTE_Fad2,T(0.25));k._tone(NOTE_Do3,T(0.25));k._tone(NOTE_Re3,T(0.5));

  //mélodie
  k._tone(NOTE_Fa5,T(1.5));
  k._tone(NOTE_Lad4,T(1.25),T(0.25));

  k._tone(NOTE_Re5,T(0.75));k._tone(NOTE_Red5,T(0.75));k._tone(NOTE_Re5,T(0.75));k._tone(NOTE_Lad4,T(0.75));
  k._tone(NOTE_Do5,T(0.5));

  //basses
  k._tone(NOTE_Red3,T(0.25));k._tone(NOTE_Fa3,T(0.25));k._tone(NOTE_Sol3,T(0.5));
  
  k._tone(NOTE_Do3,T(0.5));
  k._tone(NOTE_Red3,T(0.25));k._tone(NOTE_Fa3,T(0.25));k._tone(NOTE_Sol3,T(0.5));
  
  k._tone(NOTE_Do3,T(0.5));
  k._tone(NOTE_Red3,T(0.25));k._tone(NOTE_Fa3,T(0.25));k._tone(NOTE_Sol3,T(0.5));
  
  k._tone(NOTE_Do3,T(0.5));
  k._tone(NOTE_Red3,T(0.25));k._tone(NOTE_Fa3,T(0.25));k._tone(NOTE_Sol3,T(0.5));*/
}

void iWillSurvive(Kubot &k){
  tempo = 150;
  k._tone(NOTE_La4,T(1.5));
  k._tone(NOTE_Sol4,T(0.5));
  k._tone(NOTE_Fa4,T(1));
  k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Lad4,T(1.5));
  k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Lad4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Fa4,T(0.5));
  //
  k._tone(NOTE_Mi4,T(1.5));
  k._tone(NOTE_Re4,T(0.5));
  k._tone(NOTE_Do4,T(1));
  k._tone(NOTE_Do5,T(1));
  //
  k._tone(NOTE_La4,T(1.5));
  k._tone(NOTE_Sol4,T(0.5));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Fa4,T(0.5));k._tone(NOTE_Mi4,T(0.5));
  //
  k._tone(NOTE_Re4,T(2));
  k._tone(NOTE_La4,T(1));
  k._tone(NOTE_Lad4,T(1));
  //
  k._tone(NOTE_Lad4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Fa4,T(0.5));
  k._tone(NOTE_Mi4,T(0.5));k._tone(NOTE_Re4,T(0.5));k._tone(NOTE_Do4,T(0.5));k._tone(NOTE_Lad3,T(0.5));
  //
  k._tone(NOTE_La3,T(4));
  k._tone(NOTE_La4,T(4));
}

void harryPotter(Kubot &k){
  tempo = 152;
  k._tone(NOTE_Re4,T(1));
  //
  k._tone(NOTE_Sol4,T(1.5));
  k._tone(NOTE_Lad4,T(0.5));
  k._tone(NOTE_La4,T(1));
  //
  k._tone(NOTE_Sol4,T(2));
  k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Do5,T(3));
  //
  k._tone(NOTE_La4,T(3));
  //
  k._tone(NOTE_Sol4,T(1.5));
  k._tone(NOTE_Lad4,T(0.5));
  k._tone(NOTE_La4,T(1));
  //
  k._tone(NOTE_Fad4,T(2));
  k._tone(NOTE_Sold4,T(1));
  //
  k._tone(NOTE_Re4,T(4.90),T(0.1));/*
  k._tone(NOTE_Re4,T(1));
  //
  k._tone(NOTE_Sol4,T(1.5));
  k._tone(NOTE_Lad4,T(0.5));
  k._tone(NOTE_La4,T(1));
  //
  k._tone(NOTE_Sol4,T(2));
  k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Fa5,T(2));
  k._tone(NOTE_Mi5,T(1));
  //
  k._tone(NOTE_Red5,T(2));
  k._tone(NOTE_Si4,T(1));
  //
  k._tone(NOTE_Red5,T(1.5));
  k._tone(NOTE_Re5,T(0.5));
  k._tone(NOTE_Dod5,T(1));
  //
  k._tone(NOTE_Dod4,T(2));
  k._tone(NOTE_Lad4,T(1));
  //
  k._tone(NOTE_Sol4,T(3));*/
  
}

void nyanCat(Kubot &k){
  tempo = 150;
  
  //// A
  k._tone(NOTE_Mi5,T(0.5));k._tone(NOTE_Fad5,T(0.5));
  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Si4,T(0.25));
  //
  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_La4,T(0.5));   k._tone(NOTE_Si4,T(0.5));
  //
  k._tone(NOTE_Do5,T(0.5));  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Mi5,T(0.25));
  //
  k._tone(NOTE_Fad5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Mi5,T(0.25));k._tone(NOTE_Si4,T(0.25));
  k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));
  ////
  k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Mi5,T(0.5));
  k._tone(NOTE_Fad5,T(0.25));k._tone(NOTE_Dod5,T(0.25));  k._tone(NOTE_Mi5,T(0.25));k._tone(NOTE_Si4,T(0.25));
  //
  k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Dod5,T(0.25));
  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));
  //
  k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));
  k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Mi5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Do5,T(0.25));
  //
  k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.5));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Si4,T(0.5));
  /*
  ////Reprise
  k._tone(NOTE_Mi5,T(0.5));k._tone(NOTE_Fad5,T(0.5));
  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Si4,T(0.25));
  //
  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_La4,T(0.5));   k._tone(NOTE_Si4,T(0.5));
  //
  k._tone(NOTE_Do5,T(0.5));  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Mi5,T(0.25));
  //
  k._tone(NOTE_Fad5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Mi5,T(0.25));k._tone(NOTE_Si4,T(0.25));
  k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));
  ////
  k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Mi5,T(0.5));
  k._tone(NOTE_Fad5,T(0.25));k._tone(NOTE_Dod5,T(0.25));  k._tone(NOTE_Mi5,T(0.25));k._tone(NOTE_Si4,T(0.25));
  //
  k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Dod5,T(0.25));
  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));
  //
  k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));
  k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Mi5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Do5,T(0.25));
  //
  k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.5));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_La4,T(0.5));
  
  //// B
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  //
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_La4,T(0.25));
  k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Mi5,T(0.25));
  //
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
  //
  k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));
  k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
  ////
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  //
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Dod5,T(0.25));
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
  //
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sold4,T(0.25));
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_La4,T(0.25));
  //
  k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Mi5,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sold4,T(0.5));
  //// Reprise
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  //
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_La4,T(0.25));
  k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Mi5,T(0.25));
  //
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
  //
  k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_La4,T(0.25));
  k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
  ////
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
  //
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Dod5,T(0.25));
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
  //
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sold4,T(0.25));
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_La4,T(0.25));
  //
  k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Mi5,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Si4,T(0.5));*/
}

void starWars(Kubot &k){
  tempo = 100;

  // A
  k._tone(NOTE_Re4,T(0.33));k._tone(NOTE_Re4,T(0.33));k._tone(NOTE_Re4,T(0.33));
  ////
  k._tone(NOTE_Sol4,T(2));k._tone(NOTE_Re5,T(2));
  //
  k._tone(NOTE_Do5,T(0.33));k._tone(NOTE_Si4,T(0.33));k._tone(NOTE_La4,T(0.33));
  k._tone(NOTE_Sol5,T(2));k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Do5,T(0.33));k._tone(NOTE_Si4,T(0.33));k._tone(NOTE_La4,T(0.33));
  k._tone(NOTE_Sol5,T(2));k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Do5,T(0.33));k._tone(NOTE_Si4,T(0.33));k._tone(NOTE_Do5,T(0.33));
  k._tone(NOTE_La4,T(2));/*
  k._tone(NOTE_Re4,T(0.75));k._tone(NOTE_Re4,T(0.25));
  
  //// Reprise
   k._tone(NOTE_Sol4,T(2));k._tone(NOTE_Re5,T(2));
  //
  k._tone(NOTE_Do5,T(0.33));k._tone(NOTE_Si4,T(0.33));k._tone(NOTE_La4,T(0.33));
  k._tone(NOTE_Sol5,T(2));k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Do5,T(0.33));k._tone(NOTE_Si4,T(0.33));k._tone(NOTE_La4,T(0.33));
  k._tone(NOTE_Sol5,T(2));k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Do5,T(0.33));k._tone(NOTE_Si4,T(0.33));k._tone(NOTE_Do5,T(0.33));
  k._tone(NOTE_La4,T(2));
  k._tone(NOTE_Re4,T(0.75));k._tone(NOTE_Re4,T(0.25));
  //// B
  k._tone(NOTE_Mi4,T(1.5));k._tone(NOTE_Mi4,T(0.5));
  k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_Si4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sol4,T(0.5));
  //
  k._tone(NOTE_Sol4,T(0.33));k._tone(NOTE_La4,T(0.33));k._tone(NOTE_Si4,T(0.33));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Mi4,T(0.5));
  k._tone(NOTE_Fad4,T(1));
  k._tone(NOTE_Re4,T(0.75));k._tone(NOTE_Re4,T(0.25));
  //
  k._tone(NOTE_Mi4,T(1.5));k._tone(NOTE_Mi4,T(0.5));
  k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_Si4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sol4,T(0.5));
  //
  k._tone(NOTE_Re5,T(2));
  
  */
  
}

void YMCA(Kubot &k){
  tempo = 136;
/*
  //// Trompettes
  k._tone(NOTE_La4,T(1.5));k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Re4,T(2),T(0.5));
  //
  k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Do5,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sol4,T(0.5));
  k._tone(NOTE_Re4,T(1));
  //
 k._tone(NOTE_La4,T(1.5));k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Re4,T(2),T(0.5));
  //
  k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Do5,T(0.25));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sol4,T(0.5));
  k._tone(NOTE_Re4,T(1));
  ////
  k._tone(NOTE_La5,T(1.5));k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Re5,T(2),T(0.5));
  //
  k._tone(NOTE_La5,T(0.5));
  k._tone(NOTE_Sol5,T(0.5));k._tone(NOTE_Do6,T(0.25));
  k._tone(NOTE_La5,T(0.5));k._tone(NOTE_La5,T(0.25));k._tone(NOTE_Sol5,T(0.5));
  k._tone(NOTE_Re5,T(1));
  //
  k._tone(NOTE_Fa5,T(1.5));
  k._tone(NOTE_Fa5,T(0.25));k._tone(NOTE_Fa5,T(0.25));
  k._tone(NOTE_Fa5,T(1.5));
  k._tone(NOTE_Fa5,T(0.25));k._tone(NOTE_Fa5,T(0.25));
  //
  k._tone(NOTE_Fa5,T(4));
  
  //// Chant
  ////Young man
  k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_La4,T(0.5),T(2));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sol4,T(0.5));
  //
  k._tone(NOTE_Fa4,T(0.5));k._tone(NOTE_Sol4,T(0.5));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Do5,T(1));
  k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Do5,T(1));
  
  // Young man
  k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_La4,T(0.5),T(2));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Sol4,T(0.5));
  //
  k._tone(NOTE_Fa4,T(0.5));k._tone(NOTE_Sol4,T(0.5));
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Do5,T(1));
  k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Do5,T(1));
  //// Young man
  k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_Lad4,T(0.5),T(2));
  k._tone(NOTE_Lad4,T(0.5));k._tone(NOTE_La4,T(0.5));
  //
  k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Lad4,T(0.5));k._tone(NOTE_Re5,T(1));
  k._tone(NOTE_Fa5,T(0.5));
  k._tone(NOTE_Re5,T(1));
  
  //Need-to-be-un-hap-py
  k._tone(NOTE_Mi5,T(1.5));k._tone(NOTE_Re5,T(1.5));k._tone(NOTE_Do5,T(1.5));
  //
  k._tone(NOTE_Lad4,T(1.5));k._tone(NOTE_La4,T(1));k._tone(NOTE_Sol4,T(1));
  
  //// Trompettes
  k._tone(NOTE_Do5,T(1));k._tone(NOTE_Do5,T(1));k._tone(NOTE_Do5,T(1));k._tone(NOTE_Do5,T(1));
  k._tone(NOTE_Do5,T(0.5));
  */
  //It's fun to stay at the
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Do5,T(1));

  //YMCA
  k._tone(NOTE_Re5,T(2));
  k._tone(NOTE_Do5,T(1));
  k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_Do5,T(0.5),T(0.5));
  
  //It's fun to stay at the
  k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Do5,T(0.5));k._tone(NOTE_La4,T(0.5));
  k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Fa4,T(0.5));
  
  //YMCA
  k._tone(NOTE_Sol4,T(2));
  k._tone(NOTE_La4,T(1));
  k._tone(NOTE_Sol4,T(0.5));k._tone(NOTE_Fa4,T(1));
  k._tone(NOTE_Re4,T(1));
  
}

void crazyFrog(Kubot &k){
  tempo = 150;

  k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Sol4,T(0.25),T(0.25));
  k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Mi4,T(0.25),T(0.25));
  k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Mi4,T(0.25),T(0.25));k._tone(NOTE_La3,T(0.25),T(1));
  //
  k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Sol4,T(0.25),T(0.25));
  k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Mi4,T(0.25),T(0.25));
  k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Mi4,T(0.25),T(0.25));k._tone(NOTE_La3,T(0.25),T(1));
  //
  k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Si4,T(0.25),T(0.25));
  k._tone(NOTE_Do5,T(0.25),T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Do5,T(0.25),T(0.25));
  k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_La4,T(0.25),T(0.25));
  k._tone(NOTE_Si4,T(0.25),T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Si4,T(0.25),T(0.25));
  //
  k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Sol4,T(0.25),T(0.25));
  k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_La4,T(0.25),T(0.25));
  k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Fa4,T(0.25),T(0.25));
  k._tone(NOTE_La4,T(0.25));
}

void tiAmo(Kubot &k){
  tempo = 120;

  k._tone(NOTE_Si4,T(1.5));k._tone(NOTE_La4,T(0.5),T(1));
  k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_Dod5,T(0.5));
  //
  k._tone(NOTE_La4,T(0.5),T(1));
  k._tone(NOTE_Si4,T(1.5));k._tone(NOTE_La4,T(0.5),T(1));
  k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_Dod5,T(0.5));
  //
  k._tone(NOTE_Si4,T(0.5),T(1));
  k._tone(NOTE_Dod5,T(1.5));k._tone(NOTE_Si4,T(0.5),T(1));
  k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_Dod5,T(0.5));
  //
  k._tone(NOTE_Si4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Si4,T(0.5));
  k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_Dod5,T(0.5));
  k._tone(NOTE_Si4,T(0.5));k._tone(NOTE_La4,T(0.5));k._tone(NOTE_Si4,T(0.5));
  k._tone(NOTE_Dod5,T(0.5));k._tone(NOTE_Re5,T(0.5));k._tone(NOTE_Dod5,T(0.5));
  //
  k._tone(NOTE_La4,T(0.5));
}

void ievanPolkka(Kubot &k){
  tempo = 150;
   k._tone(NOTE_Fad4,T(0.25));
   //
   k._tone(NOTE_Dod4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25),T(0.25));
   k._tone(NOTE_Fad4,T(0.25),T(0.5));k._tone(NOTE_Sold4,T(0.25));
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fad4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_La4,T(0.25));
   //
   k._tone(NOTE_Sold4,T(0.25),T(0.25));k._tone(NOTE_Mi4,T(0.25),T(0.25));
   k._tone(NOTE_Mi4,T(0.25),T(0.25));k._tone(NOTE_Sold4,T(0.25),T(0.25));
   k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25),T(0.25));
   k._tone(NOTE_Fad4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   //
   k._tone(NOTE_Dod4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25),T(0.25));
   k._tone(NOTE_Fad4,T(0.25),T(0.5));k._tone(NOTE_Sold4,T(0.25));
   k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_La4,T(0.25));
   //
   k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Si4,T(0.25));
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25),T(0.25));
   k._tone(NOTE_Fad4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_La4,T(0.25));
   //
   k._tone(NOTE_Dod5,T(0.25),T(0.25));k._tone(NOTE_Dod5,T(0.25),T(0.25));
   k._tone(NOTE_Si4,T(0.25),T(0.25));k._tone(NOTE_La4,T(0.25),T(0.25));
   k._tone(NOTE_Sold4,T(0.25),T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   //
   k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Si4,T(0.25));
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fad4,T(0.25),T(0.5));k._tone(NOTE_La4,T(0.25));
   //
   k._tone(NOTE_Dod5,T(0.25),T(0.25));k._tone(NOTE_Dod5,T(0.25),T(0.25));
   k._tone(NOTE_Si4,T(0.25),T(0.25));k._tone(NOTE_La4,T(0.25),T(0.25));
   k._tone(NOTE_Sold4,T(0.25),T(0.25));k._tone(NOTE_Mi4,T(0.25),T(0.25));
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   //
   k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Si4,T(0.25));
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   k._tone(NOTE_La4,T(0.25),T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fad4,T(0.25),T(0.5));k._tone(NOTE_Fad4,T(0.25));
  
}

void leVolDuBourdon(Kubot &k){
  tempo = 200;
  
   k._tone(NOTE_Mi6,T(0.25));k._tone(NOTE_Red6,T(0.25));k._tone(NOTE_Re6,T(0.25));k._tone(NOTE_Dod6,T(0.25));
   k._tone(NOTE_Re6,T(0.25));k._tone(NOTE_Dod6,T(0.25));k._tone(NOTE_Do6,T(0.25));k._tone(NOTE_Si5,T(0.25));
   //
   k._tone(NOTE_Do6,T(0.25));k._tone(NOTE_Si5,T(0.25));k._tone(NOTE_Lad5,T(0.25));k._tone(NOTE_La5,T(0.25));
   k._tone(NOTE_Sold5,T(0.25));k._tone(NOTE_Sol5,T(0.25));k._tone(NOTE_Fad5,T(0.25));k._tone(NOTE_Fa5,T(0.25));
   //
   k._tone(NOTE_Mi5,T(0.25));k._tone(NOTE_Red5,T(0.25));k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));
   k._tone(NOTE_Re5,T(0.25));k._tone(NOTE_Dod5,T(0.25));k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));
   //
   k._tone(NOTE_Do5,T(0.25));k._tone(NOTE_Si4,T(0.25));k._tone(NOTE_Lad4,T(0.25));k._tone(NOTE_La4,T(0.25));
   k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fa4,T(0.25));
   //// 5
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Si3,T(0.25));
   //
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Si3,T(0.25));
   //
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));
   //
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Red4,T(0.25));
   ////9
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));
   //
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Red4,T(0.25));
   //
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Si3,T(0.25));
   //
   k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Red4,T(0.25));
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));
   ////13
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Red4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));
   k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Si3,T(0.25));
   //
   k._tone(NOTE_Do4,T(0.25));k._tone(NOTE_Dod4,T(0.25));k._tone(NOTE_Re4,T(0.25));k._tone(NOTE_Red4,T(0.25));
   k._tone(NOTE_Mi4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   //
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Lad4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   //
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   ////17
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Lad4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   //18
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   //
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Fad4,T(0.25));
   k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Mi4,T(0.25));
   //
   k._tone(NOTE_Fa4,T(0.25));k._tone(NOTE_Fad4,T(0.25));k._tone(NOTE_Sol4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Lad4,T(0.25));k._tone(NOTE_La4,T(0.25));k._tone(NOTE_Sold4,T(0.25));
   ////
   k._tone(NOTE_La4,T(0.5),T(0.5));k._tone(NOTE_La4,T(1));
   //
   k._tone(NOTE_Lad4,T(2));
   //
   k._tone(NOTE_La4,T(1));k._tone(NOTE_La4,T(1));
   //
   k._tone(NOTE_Lad4,T(2));
   
}
   
void testSong(Kubot &k){
  k._tone(NOTE_Mi5,50,30);
  k._tone(NOTE_Mi6,55,25);
  k._tone(NOTE_La6,60,10);
  k._tone(NOTE_Mi5,50,30);
  k._tone(NOTE_La6,55,25);
  k._tone(NOTE_Mi6,50,10);
  k.bendTones(1500, 2500, 20);
  k.bendTones(2499, 1500, 25);
  k.bendTones(2000, 6000, 8);
  delay(50);
  k.bendTones(5999, 2000, 13);
}

void connectionSong(Kubot &k){
  k._tone(NOTE_Mi5,50,30);
  k._tone(NOTE_Mi6,55,25);
  k._tone(NOTE_La6,60,10);
}

void disconnectionSong(Kubot &k){
  k._tone(NOTE_Mi5,50,30);
  k._tone(NOTE_La6,55,25);
  k._tone(NOTE_Mi6,50,10);
}

void happySong(Kubot &k){
  k.bendTones(1500, 2500, 20);
  k.bendTones(2499, 1500, 25);
}

void superHappySong(Kubot &k){
  k.bendTones(2000, 6000, 8);
  delay(50);
  k.bendTones(5999, 2000, 13);
}

//Musiques codées par Elise SUARD, trésorière d'Estiazik et personne de qualité.


