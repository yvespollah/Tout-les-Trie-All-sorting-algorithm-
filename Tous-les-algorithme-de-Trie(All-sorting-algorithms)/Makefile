CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.o function.o
	$(CC) $(CFLAGS) -o main main.o function.o

main.o: main.c function.h
	$(CC) $(CFLAGS) -c main.c

function.o: function.c function.h
	$(CC) $(CFLAGS) -c function.c

clean:
	rm -f *.o main
