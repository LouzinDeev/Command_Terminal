#include <stdio.h>
#include <stdlib.h>

#include "commands.c"


int main() {

	registerCommands();
	printf("Hello, Welcome to the terminal\n");

	char func[244];
	do {
		char params[244];
		printf(">> ");
		scanf("%s %s", func, params);
		if(strcmp(func, "exit")) {
			callCommand(func, params);
		}
	} while(strcmp(func, "exit"));
	return 0;
}