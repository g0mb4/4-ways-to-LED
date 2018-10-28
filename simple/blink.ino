/* blink_rgb.ino
   Simple LED blinking program.
   2016, gmb
*/

int pinR = 11;
int pinG = 12;
int pinB = 13;

#define BLINK_DELAY_MS 250	// wait time

/* the setup function runs once when you press reset or power the board */
void setup() {
  /* initialize digital pin 11, 12, 13 as an output */
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

/* the loop function runs over and over again forever */
void loop() {
  /* turn on the pins */
  digitalWrite(pinR, HIGH);   
  digitalWrite(pinG, HIGH);   
  digitalWrite(pinB, HIGH);   
  delay(BLINK_DELAY_MS);  // wait 250 ms
  /* turn off the pins */
  digitalWrite(pinR, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinB, LOW);
  delay(BLINK_DELAY_MS);  // wait 250 ms
}
