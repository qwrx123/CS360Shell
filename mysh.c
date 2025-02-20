#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers/functions.h"

#define commandSize 256
#define numTokens 10

int main(int argc, char** argv)
{
	initializeSignalHandler();

	char buffer[commandSize];

	while(true)
	{
		formatShellString();
		getUserCommand(buffer, 100);
		char* tokens[numTokens] = {0};
		parseCommand(buffer, 100, tokens, 10);
		commandChoser(tokens, 10);
	}

	exit(EXIT_SUCCESS);
}