#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#include "../headers/functions.h"

bool changeDirectory (char* directory, int length)
{
    if (length == 0)
    {
        return chdir(getenv("HOME")) == 0;
    }

    if (chdir(directory) == -1)
    {
        if (errno == ENOENT)
        {
            fprintf(stderr, "No such directory\n");
        }
        else
        {
            fprintf(stderr, "Change directory failed\n");
        }
        return false;
    }

    return true;
}

bool printDirectory()
{
    char cwd[1024];

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
        else if (i > 0 && command[i] == ' ' && command[i - 1] != ' ')
        {
            command[i] = '\0';
        }
    }

	if (command[i-1] == '\n')
    {
        command[i-1] = '\0';
    }
    
    return true;
}

bool commandChoser(char** buffer, int numTokens)
{
    if (buffer[0] == NULL)
    {
        return false;
    }

    if (strcmp(buffer[0], "cd") == 0)
    {
        if (buffer[1] == NULL)
        {
            return changeDirectory("", 0);
        }
        else
        {
            return changeDirectory(buffer[1], strlen(buffer[1]));
        }
        return true;
    }

    if (strcmp(buffer[0],"pwd") == 0)
    {
        printDirectory();
        printf("\n");
        fflush(stdout);
        return true;
    }

    if (strcmp(buffer[0], "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }

    runCommand(buffer, numTokens);

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
		if (execvp(command[0], command) == -1)
        {
            fprintf(stderr, "Failed to execute command\n");
            exit(EXIT_FAILURE);
        }
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