LIBS:=-lc -lm

CC:=gcc
CCFLAGS:=-c -Wall

LD:=gcc
LDFLAGS:=$(LIBS)

find=$(shell find -type f -name $(1))

SOURCESH:=$(call find, '*.h')
SOURCESC:=$(call find, '*.c')
OBJECTS:=$(SOURCESC:.c=.o)

#keep intermediate files
.SECONDARY:
#keep additional files
.PRECIOUS: *.map
#keyword targets
.PHONY: all clean

%.o: %.c $(SOURCESH)
	@echo ".compiling $<"
	@$(CC) $< -o $@ $(CCFLAGS)

%.elf: $(OBJECTS)
	@echo "..linking $@"
	@$(LD) $^ -o $@ $(LDFLAGS) -Wl,-Map,$*.map

all: build.elf
	@echo "...completing $^"

clean:
	@echo ".cleaning"
	@rm -f $(call find, '*.o')
	@rm -f $(call find, '*~')
	@rm -f *.elf
	@rm -f *.map

