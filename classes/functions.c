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
    if (length == 0 || command[0] == '\n')
    {
        return false;
    }

    char* argv[10] = {0};
    
    int currentArg = 0;

    if (command[0] != ' ')
    {
        argv[currentArg] = &command[0];
        currentArg++;
    }

    int i = 0;
    for (; i < length && command[i] != '\0'; i++)
    {
        if (command[i] == ' ' && i < length - 1 && command[i+1] != ' ')
        {
            if (currentArg >= 10)
            {
                return false;
            }

            argv[currentArg] = &command[i + 1];
            command[i] = '\0';
            currentArg++;
        }
    }

	if (command[i-1] == '\n')
    {
        command[i-1] = '\0';
    }
    

    int status;
	int pid = fork();

	if (pid == -1)
	{
		perror("Failed to create processes");
	}

	if (pid == 0)
	{
		execvp(argv[0], argv);
        perror("what");
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