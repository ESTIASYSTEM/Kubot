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

//bras
#define PIN_RA 7
#define PIN_LA 6
//shoulders
#define PIN_LS 12
#define PIN_RS 13

Kubot Kubo;

Oscillator rightArm;
Oscillator leftArm;
Oscillator rightShoulder;
Oscillator leftShoulder;
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

 unsigned char j; 
//Cablage du module (gnd et +V) utilise 3 pins
int Max7219_pinCLK = A0;  
int Max7219_pinCS = A1;
int Max7219_pinDIN = A2;

//Définition des pixels a eclairer
//0-9 puis A-Z soit 10+26 = 36 caractères
//{0x00,0x00,0x00,0x81,0x7E,0x42,0x24,0x18},//smiley

unsigned char disp1[1][8]={ //gauche vers droite bas vers haut
{0b00111100, 0b01000010, 0b10000001, 0b10000001, 0b10000001, 0b01000010, 0b00111100, 0b00000000}//rond
};

//Autre exemple, caracteres speciaux (a definir soi meme)
//Voir explications sur http://tiptopboards.com/arduino_tutoriel/posting.php?mode=edit&f=2&p=6
//{0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55},  //damier1
// {0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA},  //damier2

//Ecriture d'un caractere 8x8
void Write_Max7219_byte(unsigned char DATA)
{
            unsigned char i;
       digitalWrite(Max7219_pinCS,LOW);
       for(i=8;i>=1;i--)
          {
             digitalWrite(Max7219_pinCLK,LOW);
             digitalWrite(Max7219_pinDIN,DATA&0x80);// Extracting a bit data
             DATA = DATA<<1;
             digitalWrite(Max7219_pinCLK,HIGH);
           }
}

//Ecriture elementaire d une seule rangee
void Write_Max7219(unsigned char address,unsigned char dat)
{
        digitalWrite(Max7219_pinCS,LOW);
        Write_Max7219_byte(address);           //address，code of LED
        Write_Max7219_byte(dat);               //data，figure on LED
        digitalWrite(Max7219_pinCS,HIGH);
}

//Initialisation du module Max 7219
void Init_MAX7219(void)
{
 Write_Max7219(0x09, 0x00);       //decoding ：BCD
 Write_Max7219(0x0a, 0x03);       //brightness
 Write_Max7219(0x0b, 0x07);       //scanlimit；8 LEDs
 Write_Max7219(0x0c, 0x01);       //power-down mode：0，normal mode：1
 Write_Max7219(0x0f, 0x00);       //test display：1；EOT，display：0
}


void setup()
{

  //Set the servo pins
  Kubo.initialize(PIN_YL,PIN_YR,PIN_RL,PIN_RR);

  // Configuration des bras
  rightArm.attach(PIN_RA);
  leftArm.attach(PIN_LA);
  rightShoulder.attach(PIN_RS);
  leftShoulder.attach(PIN_LS);

//  connectionSong(Kubo); // on joue le son de connection

  rightArm.SetPosition(90);
  leftArm.SetPosition(90);

  //Pins a utiliser
   pinMode(Max7219_pinCLK,OUTPUT);
   pinMode(Max7219_pinCS,OUTPUT);
   pinMode(Max7219_pinDIN,OUTPUT);
   delay(50);  //Initialiser
   Init_MAX7219();

  Kubo.home();
  delay(50);

}



///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop()
{
  Kubo.home();

for(j=0;j<1;j++)
 {  //Faire défiler les caracteres a afficher
  for(int i=1;i<9;i++)  //Afficher un caractere à la fois
   Write_Max7219(i,disp1[j][i-1]);
  delay(150);  //Attente pour laisser le temps de lire

 }

  rightArm.SetPosition(90);
  leftArm.SetPosition(90);
  rightShoulder.SetPosition(90);
  leftShoulder.SetPosition(90);
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
  rightShoulder.SetPosition(180);
  leftShoulder.SetPosition(180);

  Kubo._tone(NOTE_Do7,1000);
  Kubo.bend();
  Kubo.home();

  rightArm.SetPosition(90);
  leftArm.SetPosition(90);
  rightShoulder.SetPosition(90);
  leftShoulder.SetPosition(90);

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
  rightShoulder.SetPosition(90);
  leftShoulder.SetPosition(90);

  Kubo.glissando(NOTE_Do7,NOTE_Do0,1000);
  Kubo.tiptoeSwing();
  Kubo.home();

  rightArm.SetPosition(180);
  leftArm.SetPosition(180);
  rightShoulder.SetPosition(180);
  leftShoulder.SetPosition(180);

  Kubo.glissando(NOTE_Do0,NOTE_Do7,1000);
  Kubo.moonwalker();
  Kubo.home();

  rightArm.SetPosition(120);
  leftArm.SetPosition(120);
  rightShoulder.SetPosition(120);
  leftShoulder.SetPosition(120);


  Kubo.jitter();
  Kubo.home();

}
