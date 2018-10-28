AC=../../../avr-gcc/bin/avr-gcc
OBJCOPY=../../../avr-gcc/bin/avr-objcopy
DUDE=../../../avr-gcc/bin/avrdude

SRC=blink

ACFLAGS=-Os -DF_CPU=16000000UL -mmcu=atmega328p -I../../avr-gcc/avr/include -nostartfiles $(SRC).S -o $(SRC)
OBJFLAGS=-O ihex -R .eeprom $(SRC) $(SRC).hex
DUDEFLAGS=-F -V -c arduino -p ATMEGA328P -P COM3 -b 115200 -U flash:w:$(SRC).hex

all:
	$(AC) $(ACFLAGS)
	$(OBJCOPY) $(OBJFLAGS)
	$(DUDE) $(DUDEFLAGS)
	
	