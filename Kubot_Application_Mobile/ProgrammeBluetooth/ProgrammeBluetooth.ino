//Codé par Florent Paulin, avec une base de Masson Dimitri :)

// Appel de la bibliothèque Kubot
#include <Kubot.hpp>
//Appel de la biblio des sons
#include "Kubot_Sounds.hpp"
#include <Servo.h>
#include <Oscillator.h>
#include <US.h>

String bluetoothMessage = "" ;
int tempo = 200;

//Instanciation de l'objet Kubot kubo
Kubot kubo;

//Rappel des pins des servomoteurs:
//               ---------------
//              |     O   O     |
//              |---------------|
//  YR pin 3==> |               | <== YL  pin 2
//               ---------------
//                  ||     ||
//  RR pin 5==>   -----   ------  <== RL pin 4
//               |-----   ------|

//Definition des pins des servomot'
#define PIN_YR 3
#define PIN_YL 2
#define PIN_RR 5
#define PIN_RL 4

////////////////////////////////////////////////////
//Boucle exécutée une fois: configuration du robot//
////////////////////////////////////////////////////
void setup()
{
  //Set the communication speed between the arduino and the shield
  Serial.begin( 9600 ) ;

  //Initialisation du robot Kubot:
  kubo.init( PIN_YL , PIN_YR , PIN_RL , PIN_RR );

  connectionSong(kubo); // on joue le son de connection
  kubo.home(); //Met le Kubot à sa position initiale
  delay(50); //Tempo de stabilisation
  happySong(kubo); //Joue le son Happy
}

/////////////
void loop()//
/////////////
{
  //While there is data to read
  while ( Serial.available() )
  {
    delay(10) ; //Stability fix : Small delay between reads

    //Read one character
    char c = Serial.read() ;
    //append character if one has been read
    if ( c != -1 )
    {
      bluetoothMessage += c ;
    }
  } //Fin de la boucle dataToRead


  if ( bluetoothMessage.length () > 0 )
  {
    if (bluetoothMessage == "avancer")
    {
      kubo.walk(2 , 1000 , FORWARD);
    }
    if (bluetoothMessage == "reculer")
    {
      kubo.walk(2 , 1000 , BACKWARD );
    }
    if (bluetoothMessage == "gauche")
    {
      kubo.turn(4 , 1000 , LEFT );
    }
    if (bluetoothMessage == "droite")
    {
      kubo.turn(4 , 1000 , RIGHT);
    }
    if (bluetoothMessage == "chanter") {
      thunderstruck(kubo);
    }
    if (bluetoothMessage == "danser")
    {
      kubo.shakeLeg(1, 2000, LEFT);
      delay(50);
      kubo.shakeLeg(1, 2000, RIGHT);
      delay(50);
      kubo.bend(1, 2000, LEFT);
      delay(50);
    }
    Serial.print( bluetoothMessage ) ;
    //Reset bluetooth message
    bluetoothMessage = "" ;
    //Remise en position initiale le Kubot
    kubo.home();

  } //Fin de la boucle Message

} //Fin de la boucle infinie

/////////////////////////
//Fonctions//////////////
/////////////////////////
int T(float nbTemps) {
  float duree;                    //tempo = nb de pulsations par minute
  duree = nbTemps * 60000 / tempo; //durée = nbTemps * 1min/tempo
  return duree;                   //  (1min = 60 000ms)
}

void connectionSong(Kubot &k)
{
  k._tone(NOTE_Mi5, 50, 30);
  k._tone(NOTE_Mi6, 55, 25);
  k._tone(NOTE_La6, 60, 10);
}

void disconnectionSong(Kubot &k)
{
  k._tone(NOTE_Mi5, 50, 30);
  k._tone(NOTE_La6, 55, 25);
  k._tone(NOTE_Mi6, 50, 10);
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
  delay(50);
  k.bendTones(500, 2000, 50);
  delay(50);
  k.bendTones(5999, 2000, 13);
  delay(500);
  k.bendTones(500, 5000, 1);
}

void thunderstruck(Kubot &k) //Par Elise Suard, Promo 2019, Trésoriere EstiaZic, modifié par Florent Paulin
{
  tempo = 130;

  k._tone(NOTE_Si5, T(0.25));

  //4-0-7-0
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25)); k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25)); k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25)); k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  //
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));

  //5-0-8-0
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  //
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Sol6, T(0.25));  k._tone(NOTE_Si5, T(0.25));

  //12-0-10-0-9-0-10-0-9-0-7-0-9-0-5-0
  k._tone(NOTE_Si6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_La6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Sold6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_La6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Sold6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Sold6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  //
  k._tone(NOTE_Fad6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));
  k._tone(NOTE_Mi6, T(0.25));  k._tone(NOTE_Si5, T(0.25));  k._tone(NOTE_Red6, T(0.25));  k._tone(NOTE_Si5, T(0.25));




}
