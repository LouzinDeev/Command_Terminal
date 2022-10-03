#include "commands.h"

void found(const char* params) {
	for(int i=0; i<MAX_COMMANDS; ++i) {
		if(!strcmp(params, cmd[i].name)) {
			printf("\nCommand %s \t %s \n\n", params, cmd[i].desc);
			break;
		}
		if(i == MAX_COMMANDS -1)
			printf("Command %s doent's exist", params);
	}
}

void say(const char* params) {
	printf("%s\n", params);
}

void github(const char* params) {
	char addr[200];
	strncpy(addr, params, 200);
	char cmd_command[500];
	sprintf(cmd_command, "cmd.exe /c \"cd github_clones && git clone %s\"", addr); 
	system(cmd_command);
}

void registerCommands() {
	cmd[0].name = "found";
	cmd[0].desc = "Found a command";
	cmd[0].func = found;

	cmd[1].name = "say";
	cmd[1].desc = "Print a string";
	cmd[1].func = say;

	cmd[2].name = "github";
	cmd[2].desc = "Clones a github repo";
	cmd[2].func = github;
}

void callCommand(const char* cmdname, const char* const _format, ...) {
	for(int i=0; i<MAX_COMMANDS; i++) {
		if(!strcmp(cmd[i].name, cmdname)) {
			cmd[i].func(_format);
			break;
		}
		if(i == MAX_COMMANDS -1)
			printf("Command %s doent's exist\n", cmdname);
	}
}