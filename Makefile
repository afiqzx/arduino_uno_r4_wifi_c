CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
#LD_SCRIPT=./linker_script.ld
LD_SCRIPT=./link.ld
#LD_SCRIPT=./fsp.ld
LIB_PATH=-L/home/afiq/.arduino15/packages/arduino/tools/arm-none-eabi-gcc/7-2017q4/arm-none-eabi/lib/hard
CFLAGS=-mcpu=cortex-m4 -nostdlib -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T $(LD_SCRIPT) -DF_CPU=48000000 -fno-builtin
#$(LIB_PATH) -lc -lm -lnosys
#-c
OUTPUT=output.bin
BIN_OUTPUT=output.elf.bin
IHEX=output.elf.hex
PORT=/dev/ttyACM0
FILES=$(wildcard src/*.c)

.PHONY=compile objcopy load clean


all: $(BIN_OUTPUT)


$(OUTPUT): $(FILES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(FILES)

$(BIN_OUTPUT): $(OUTPUT)
	$(OBJCOPY) -O binary $(OUTPUT) $(BIN_OUTPUT)
#$(OBJCOPY) -O ihex -j .text -j .data $(OUTPUT) $(IHEX)


load: FORCE
	arduino-cli upload -b arduino:renesas_uno:unor4wifi -i ./$(BIN_OUTPUT) -p $(PORT) --verbose

clean:
	rm -f $(OUTPUT) $(BIN_OUTPUT) $(IHEX)

FORCE: ;

