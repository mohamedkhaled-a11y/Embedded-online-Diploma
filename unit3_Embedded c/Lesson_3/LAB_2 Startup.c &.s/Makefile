

#Make_File by ENG:Mohamed_khaled

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) 
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
projName= learn-in-depth_cortexM3

all: $(projName).hex
	@echo "=================Build done successfully================"


%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	 $(CC)gcc.exe -c $(INCS)  $(CFLAGS)  $< -o $@



$(projName).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld  $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map


$(projName).hex: $(projName).elf
	$(CC)objcopy.exe -O binary $< $@

lean_all:
	rm -rf *.o *.elf *.hex
clean:
	rm -rf *.elf *.hex

