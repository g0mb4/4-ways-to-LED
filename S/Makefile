ARDUINOPATH="c:\Program Files (x86)\Arduino"

AS=$(ARDUINOPATH)\hardware\tools\avr\bin\avr-gcc
OBJCOPY=$(ARDUINOPATH)\hardware\tools\avr\bin\avr-objcopy
DUDE=$(ARDUINOPATH)\hardware\tools\avr\bin\avrdude

DUDEPORT=COM8
SRC=blink

ASFLAGS=-Os -DF_CPU=16000000UL -mmcu=atmega328p -nostartfiles $(SRC).S -o $(SRC)
OBJFLAGS=-O ihex -R .eeprom $(SRC) $(SRC).hex
DUDEFLAGS=-F -V -c arduino -p ATMEGA328P -C $(ARDUINOPATH)\hardware\tools\avr\etc\avrdude.conf -P $(DUDEPORT) -b 115200 -U flash:w:$(SRC).hex

all:
	$(AS) $(ASFLAGS)
	$(OBJCOPY) $(OBJFLAGS)
	$(DUDE) $(DUDEFLAGS)

clean:
	rm -rf $(SRC) $(SRC).hex a.out
	