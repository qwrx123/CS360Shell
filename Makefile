CC = gcc
CFLAGS = -g

all:
	make bin/mysh

bin/mysh: objects/mysh.o objects/functions.o
	mkdir -p bin
	${CC} -o bin/mysh objects/mysh.o objects/functions.o

objects/mysh.o: mysh.c
	mkdir -p objects
	${CC} -o objects/mysh.o -c mysh.c

objects/functions.o: classes/functions.c
	mkdir -p objects
	${CC} -o objects/functions.o -c classes/functions.c

clean:
	rm -f bin/*
	rm -f objects/*