#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COMMANDS 3
struct command {
	char* name;
	char* desc;
	void (*func)(const char* params);
};
struct command cmd[MAX_COMMANDS];

void createCommand(const int id, const char* name, const char* desc, void (*func)(const char* params));
void registerCommands();
void callCommand(const char* cmdname, const char* const _format, ...);

#endif