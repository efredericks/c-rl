CC = gcc
# CFLAGS = -lpanel -lm -lraylib -I./include/
# CFLAGS = -lpanel -lncurses -lm -lSDL2 -lraylib -I./include/
CFLAGS = -lpanel -lncurses -lm -I./include/
SOURCES = ./src/*.c

all: rogue run clean

rogue:
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue

clean:
	rm rogue