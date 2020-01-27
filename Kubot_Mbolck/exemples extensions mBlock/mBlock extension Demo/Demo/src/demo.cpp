#include "demo.h"
DemoClass::DemoClass(){
	pinMode(13,OUTPUT);
  level = 0;
}

void DemoClass::blink(){
	level = 1- level;
	digitalWrite(13,level);
}