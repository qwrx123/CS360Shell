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
    char cwd[1024]; // Buffer to store the current working directory

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("pwd");
        return false;   
    }

    printf(cwd);

    return true;
}

bool formatShellString()
{
    if (!printDirectory())
    {
        return false;
    }

    printf("$myshell > ");
    fflush(stdout);
}

bool parseCommand(char* command, int lengthCommand, char** tokenized, int lengthTokanized)
{
    if (lengthCommand == 0 || command[0] == '\n')
    {
        return false;
    }
    
    int currentArg = 0;

    if (command[0] != ' ')
    {
        tokenized[currentArg] = &command[0];
        currentArg++;
    }

    int i = 0;
    for (; i < lengthCommand && command[i] != '\0'; i++)
    {
        if (command[i] == ' ' && i < lengthCommand - 1 && command[i+1] != ' ')
        {
            if (currentArg >= lengthTokanized)
            {
                return false;
            }

            tokenized[currentArg] = &command[i + 1];
            command[i] = '\0';
            currentArg++;
        }
    }

	if (command[i-1] == '\n')
    {
        command[i-1] = '\0';
    }
    
    return true;
}

bool runCommand(char** command, int length)
{
    int status;
	int pid = fork();

	if (pid == -1)
	{
		perror("Failed to create processes");
        return false;
	}

	if (pid == 0)
	{
		execvp(command[0], command);
	}
	else
	{
		wait(0);
    }
    return true;
}

bool getUserCommand(char* buffer, int bufferSize)
{
    if (fgets(buffer, bufferSize, stdin) == 0)
    {
        return false;
    }

    return true;
}