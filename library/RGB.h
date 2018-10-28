/* RGB.h
   LED blinking library - header file
   2016, gmb
*/

/* inclusion guard */
#ifndef __RGB_H__
#define __RGB_H__

#include "Arduino.h"	// headr file for the Arduino functions

#define BLINK_DELAY_MS 250	// wait time

class RGB
{
public:
	/* member functions */
	RGB(int R, int G, int B);	// constructor
	void on(void);
	void off(void);
	void sleep(void);
private:
	int _pinR, _pinG, _pinB;
};

#endif