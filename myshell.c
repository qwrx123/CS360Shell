#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers/functions.h"

int main(int argc, char** argv)
{
	int pid;

	while(true)
	{
		runCommand("", 0);
	}
	exit(EXIT_SUCCESS);
}