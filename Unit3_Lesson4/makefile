CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
ProjectName = unit3_Lesson4_cortexM4

all: $(ProjectName).bin
	@echo "===========Build is done============="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) $(LIBS) -c -std=c99 $< -o $@

$(ProjectName).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(ProjectName).elf $(ProjectName).axf

$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@


clear:
	rm *.o *.elf *.bin *.hex
	@echo "Everything's clear!"