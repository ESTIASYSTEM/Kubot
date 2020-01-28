//Code généré par mBlovkV3 a mettre sur le kubot pour tester le programme ecrit par les gamins.

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include "Kubot.hpp"
#include "Kubot_Sounds.hpp"
				
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
#define PIN_YR 3
#define PIN_YL 2
#define PIN_RR 5
#define PIN_RL 4
#define PIN_RA 7
#define PIN_LA 6
Kubot Kubo;
Oscillator rightArm;
Oscillator leftArm;
String position = " ";
int tempo=190;
int T(float nbTemps){
      float duree;
    	duree = nbTemps*60000/tempo;
    	return duree;
}



void setup(){
    Kubo.initialize(PIN_YL,PIN_YR,PIN_RL,PIN_RR);
    rightArm.attach(PIN_RA);
    leftArm.attach(PIN_LA);
    rightArm.SetPosition(90);
    leftArm.SetPosition(90);
    Kubo.home();
    delay(50);
    
    
}

void loop(){
    
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

