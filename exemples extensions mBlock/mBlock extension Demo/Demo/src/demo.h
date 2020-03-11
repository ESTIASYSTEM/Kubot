#ifndef demo_h
#define demo_h

#include <Arduino.h>
///@brief Class for DemoClass
class DemoClass
{
	public:
		DemoClass();
		void blink();
	private:
		int level;
};

#endif