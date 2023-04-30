#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	char* command = strchr(argv[0], '/');
	if(command == NULL)
		command = argv[0];
	else
		command += 1;
	if(strcmp(command, "minibusybox") == 0)
		printf("Available commands:\n \n");
	else if(argc == 2){
		if(strcmp(command, "command") == 0)
			return function(argv[1]);
		else
			printf("Unknown command\n");
	}else
		printf("Usage: %s <argument>\n", argv[0]);
	return 0;
}