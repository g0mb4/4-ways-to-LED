; blink.S
; LED blinking program - assembly implementation for avr-gcc 
; 2016, gmb

; allow us to use names like "PORTB"
#define __SFR_OFFSET 0

; include necessary headers
#include <avr/io.h>

; wait time
#define BLINK_DELAY_MS 250

start:
	sbi	DDRB, PORTB6 ; Set BIt, set PORTB6 (board 13) as output
	sbi	DDRB, PORTB5 ; Set BIt, set PORTB5 (board 12) as output
	sbi	DDRB, PORTB4 ; Set BIt, set PORTB4 (board 11) as output

blink:
	ldi  	r20, BLINK_DELAY_MS	; LoaD Immediate, BLINK_DELAY_MS -> r20
	call 	delay_n_ms			; CALL the "delay" function
	sbi 	PORTB, PORTB6		; Set BIt, turn on PORTB6
	sbi 	PORTB, PORTB5       ; Set BIt, turn on PORTB5
	sbi 	PORTB, PORTB4       ; Set BIt, turn on PORTB4
	ldi  	r20, BLINK_DELAY_MS ; LoaD Immediate, BLINK_DELAY_MS -> r20
	call	delay_n_ms          ; CALL the "delay" function
	cbi  	PORTB, PORTB6	    ; Clear BIt, turn off PORTB6
	cbi  	PORTB, PORTB5       ; Clear BIt, turn off PORTB5
	cbi  	PORTB, PORTB4       ; Clear BIt, turn off PORTB4
	jmp     blink               ; loop

; "delay" function
;  delays about r20 * 1ms , destroys r20, r30, and r31
;  1 millisecond is about 16000 cycles at 16MHz
;  the basic loop takes about 5 cycles, so we need about 3000 loops
delay_n_ms:
	ldi 	r31, 3000 >> 8	; LoaD Immediate value, high(3000) -> r31
	ldi 	r30, 3000 & 255	; LoaD Immediate value, low(3000) -> r30
delaylp:
	sbiw 	r30, 1       ; Subtract Immediate from Word, lower cycle counter
	brne 	delaylp      ; BRanch if Not Equal, if not zero -> loop subsection, else :
	subi 	r20, 1       ; SUBtract Immediate, lower the main counter
	brne 	delay_n_ms   ; BRanch if Not Equal, if not zero -> loop section, else :
	ret                  ; RETurn
