CC = cc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

all: battleship

battleship: main.c
	$(CC) $(CFLAGS) main.c -o battleship

run: battleship
	./battleship

clean:
	rm -f battleship
