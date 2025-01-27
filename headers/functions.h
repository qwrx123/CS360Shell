#include <stdbool.h>

bool initializeSignalHandler();

void signalHandler(int signal);

bool changeDirectory(char* directory, int length);

bool printDirectory();

bool formatShellString();

bool commandChoser(char** buffer, int bufferSize);

bool runCommand(char** buffer, int bufferSize);

bool parseCommand(char* command, int lengthCommand, char** tokanized, int lengthTokanized);

bool getUserCommand(char* buffer, int bufferSize);