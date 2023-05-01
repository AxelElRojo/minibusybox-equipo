#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uname/libuname.h"

int main(int argc, char** argv){
	// strchr() returns the last appearance of a character
	// If the name contains a / it means the program's name starts after the last slash
	// If not, it means the program's name starts on argv[0][0] (i.e. executed from $PATH).
	
	char* command = strchr(argv[0], '/');
	if(command == NULL)
		command = argv[0];
	else
		command += 1;
	if(strcmp(command, "minibusybox") == 0)
		printf("Available commands:\n - sleep_\n - cat_\n - uname_\n - lsmod_\n");
	else if(argc == 1){
		if(strcmp(command, "uname_") == 0)
		{
			unameValidation(argc,argv);
		}
		else
			printf("Unknown command\n");
	}else
		printf("Usage: %s <argument>\n", argv[0]);
	return 0;
}