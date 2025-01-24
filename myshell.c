#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers/functions.h"

int main(int argc, char** argv)
{

	int pid;

	char buffer[100];

	while(true)
	{
		getUserCommand(buffer, 100);
		runCommand(buffer, 100);
	}
	exit(EXIT_SUCCESS);
}