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
  Kubo.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR);

  
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
      
  happySong(Kubo);    
  Kubo.tiptoeSwing(1,500,20);     
  superHappySong(Kubo); 
  Kubo.tiptoeSwing(1,500,20); 
  

  // arret de la boucle
  Kubo.home();
  disconnectionSong(Kubo);
  while(true);
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
  k.bendTones(1500, 2500, 20);
  k.bendTones(2499, 1500, 25);
}

void superHappySong(Kubot &k)
{
  k.bendTones(2000, 6000, 8);
  delay(50);
  k.bendTones(5999, 2000, 13);
}




