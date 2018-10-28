CC=../../../avr-gcc/bin/avr-gcc
OBJCOPY=../../../avr-gcc/bin/avr-objcopy
DUDE=../../../avr-gcc/bin/avrdude

SRC=blink

CCFLAGS1=-Os -DF_CPU=16000000UL -mmcu=atmega328p -I../../avr-gcc/avr/include -c -o $(SRC).o $(SRC).c
CCFLAGS2=-mmcu=atmega328p $(SRC).o -o $(SRC)
OBJFLAGS=-O ihex -R .eeprom $(SRC) $(SRC).hex
DUDEFLAGS=-F -V -c arduino -p ATMEGA328P -P COM3 -b 115200 -U flash:w:$(SRC).hex

all:
	$(CC) $(CCFLAGS1)
	$(CC) $(CCFLAGS2)
	$(OBJCOPY) $(OBJFLAGS)
	$(DUDE) $(DUDEFLAGS)
	
	