#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "headers/functions.h"

int main(int argc, char** argv)
{
	int pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Failed to create processes");
	}

	if (pid == 0)
	{
		printf("From child\n");
	}
	else if (pid != 0)
	{
		waitpid(pid, NULL, 0);
		printf("From parent\n");
	}
	exit(EXIT_SUCCESS);
}