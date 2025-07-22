CC = gcc
CFLAGS = -lpanel -lncurses -lm -lSDL2 -I./include/
SOURCES = ./src/*.c

all: rogue run clean

rogue:
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue

clean:
	rm rogue