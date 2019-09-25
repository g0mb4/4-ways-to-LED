ARDUINOPATH="c:\Program Files (x86)\Arduino"

CC=$(ARDUINOPATH)\hardware\tools\avr\bin\avr-gcc
OBJCOPY=$(ARDUINOPATH)\hardware\tools\avr\bin\avr-objcopy
DUDE=$(ARDUINOPATH)\hardware\tools\avr\bin\avrdude

DUDEPORT=COM8
SRC=blink

CCFLAGS1=-Os -DF_CPU=16000000UL -mmcu=atmega328p -I../../avr-gcc/avr/include -c -o $(SRC).o $(SRC).c
CCFLAGS2=-mmcu=atmega328p $(SRC).o -o $(SRC)
OBJFLAGS=-O ihex -R .eeprom $(SRC) $(SRC).hex
DUDEFLAGS=-F -V -c arduino -p ATMEGA328P -C $(ARDUINOPATH)\hardware\tools\avr\etc\avrdude.conf -P $(DUDEPORT) -b 115200 -U flash:w:$(SRC).hex

all:
	$(CC) $(CCFLAGS1)
	$(CC) $(CCFLAGS2)
	$(OBJCOPY) $(OBJFLAGS)
	$(DUDE) $(DUDEFLAGS)
	
clean:
	rm -rf $(SRC) $(SRC).o $(SRC).hex
	
	