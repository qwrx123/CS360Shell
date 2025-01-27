CC = gcc
CFLAGS = -g

all:
	make bin/myshell

bin/myshell: objects/myshell.o objects/functions.o
	mkdir -p bin
	${CC} -o bin/myshell objects/myshell.o objects/functions.o

objects/myshell.o: myshell.c
	mkdir -p objects
	${CC} -o objects/myshell.o -g -c myshell.c

objects/functions.o: classes/functions.c
	mkdir -p objects
	${CC} -o objects/functions.o -g -c classes/functions.c

clean:
	rm -f bin/*
	rm -f objects/*