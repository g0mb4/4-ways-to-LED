/* blink.ino
   Simple LED blinking program using a custom library.
   2016, gmb
*/

#include "RGB.h"  // include the header file

RGB rgb(11, 12, 13);  // declare the lib

void setup()
{
	/* nothing to do here */
}

void loop() 
{
    rgb.on();       // turn on the pins
    rgb.sleep();	// wait 250 ms
    rgb.off();      // turn off the pins
    rgb.sleep(); 	// wait 250 ms
}
