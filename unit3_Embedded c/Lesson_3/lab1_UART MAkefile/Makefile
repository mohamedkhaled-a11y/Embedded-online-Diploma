
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS= 
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
all: learn-in-depth.bin
	@echo "=================Build done successfully================"
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	 $(CC)gcc.exe -c $(INCS)  $(CFLAGS)  $< -o $@



Learn-in-depth.elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld  $(LIBS) $(OBJ) startup.o -o $@ -Map=Map_file.map


Learn-in-depth.bin: Learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@


clean_all:
	rm -rf *.o *.elf *.bin
clean:
	rm -rf *.elf *.bin