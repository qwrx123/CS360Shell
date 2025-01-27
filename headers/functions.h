#include <stdbool.h>

bool changeDirectory(char* directory, int length);

bool printDirectory();

bool formatShellString();

bool runCommand(char** buffer, int bufferSize);

bool parseCommand(char* command, int lengthCommand, char** tokanized, int lengthTokanized);

bool getUserCommand(char* buffer, int bufferSize);