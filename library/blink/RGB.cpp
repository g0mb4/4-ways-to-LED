/* RGB.cpp
   LED blinking library - code implementation
   2016, gmb
*/

#include "RGB.h"

/* constructor */
RGB::RGB(int R, int G, int B){
	/* set up private variables */
	_pinR = R;
	_pinG = G;
	_pinB = B;
	
	/* initialize pins as an output */
	pinMode(_pinR, OUTPUT);
	pinMode(_pinG, OUTPUT);
	pinMode(_pinB, OUTPUT);
	
	/* turn off the pins */ 
	digitalWrite(_pinR, LOW);
	digitalWrite(_pinG, LOW);
	digitalWrite(_pinB, LOW);
}

/* turn on the pins */
void RGB::on(void)
{
	digitalWrite(_pinR, HIGH);
	digitalWrite(_pinG, HIGH);
	digitalWrite(_pinB, HIGH);
}

/* turn off the pins */
void RGB::off(void)
{
	digitalWrite(_pinR, LOW);
	digitalWrite(_pinG, LOW);
	digitalWrite(_pinB, LOW);
}

/* wait */
void RGB::sleep(void)
{
	delay(BLINK_DELAY_MS);  
}

    