/* blink.c
   LED blinking program - C implementation for avr-gcc 
   2016, gmb
*/

/* include necessary headers */
#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 250	// wait time

/* start of the program */
int main(void)
{
	/* set pin 4, 5, 6 of PORTB for output (BOARD 11, 12, 13) */
	DDRB = 0;
	DDRB |= _BV(PORTB6) | _BV(PORTB5) | _BV(PORTB4);

	/* infintie loop */
	for(;;) {
		/* set pin 4, 5, 6 high to turn led on */
		PORTB |= _BV(PORTB6) | _BV(PORTB5) | _BV(PORTB4);
		_delay_ms(BLINK_DELAY_MS);	// wait

		/* set pin 4, 5, 6 low to turn led off */
		PORTB &= ~_BV(PORTB6);
		PORTB &= ~_BV(PORTB5);
		PORTB &= ~_BV(PORTB4);
		_delay_ms(BLINK_DELAY_MS);	// wait
	}
}
