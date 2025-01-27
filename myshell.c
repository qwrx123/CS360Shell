#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers/functions.h"

#define commandSize 100
#define numTokens 10

int main(int argc, char** argv)
{
	char buffer[commandSize];
	char* tokens[numTokens];

	while(true)
	{
		formatShellString();
		getUserCommand(buffer, 100);
		parseCommand(buffer, 100, tokens, 10);
		commandChoser(tokens, 10);
	}

	exit(EXIT_SUCCESS);
}