#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../headers/functions.h"

bool changeDirectory (char* directory, int length)
{
    return false;
}

bool printDirectory()
{
    return false;
}

bool runCommand(char* command, int length)
{
    char* argv[3];
    argv[0] = "echo";
    argv[1] = command;
    argv[2] = NULL;
	
    int status;
	int pid = fork();

	if (pid == -1)
	{
		perror("Failed to create processes");
	}

	if (pid == 0)
	{
		execvp("echo", argv);
	}
	else
	{
		wait(0);
		printf("myshell$ ");
        fflush(stdout);
		//sleep(1);
		
    }
    return false;
}

bool getUserCommand(char* buffer, int bufferSize)
{
    if (fgets(buffer, bufferSize, stdin) == 0)
    {
        return false;
    }

    return true;
}