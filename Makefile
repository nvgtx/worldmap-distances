CC=gcc
LD=gcc
LIBS=-lm
CFLAGS=-Wall $(LIBS)
LDFLAGS=-Wall $(LIBS)

SRCS=$(wildcard *.c) $(wildcard */*.c)
OBJS=$(SRCS:.c=.o)

.PHONY: all
all: main.elf
	@ echo "...completing"

main.elf: $(OBJS)
	@ echo "..linking"
	$(LD) $^ -o $@ $(LDFLAGS)

%.o: %.c
	@ echo ".compiling"
	$(CC) -c $^ -o $@ $(CFLAGS)

.PHONY: clean
clean:
	@ echo ".cleaning"
	@rm -rf *.o
	@rm -rf */*.o
	@rm -rf *.elf
	@rm -rf *.map
	@rm -rf *~
	@rm -rf */*~

