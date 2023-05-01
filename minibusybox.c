#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mkdir/libmkdir.h"
#include "rm/librm.h"
#include "uname/libuname.h"

int main(int argc, char** argv){
	char* command = strchr(argv[0], '/');
	if(command == NULL)
		command = argv[0];
	else
		command += 1;
	if(strcmp(command, "minibusybox") == 0)
		printf("Available commands:\n - mkdir\n - rm\n - uname\n");
	else if(argc == 2){
		if(strcmp(command, "mkdir") == 0)
			return createDirectory(argv[1]);
		else if(strcmp(command, "rm") == 0)
			return s_rm(argc, argv);
		else if(strcmp(command, "uname") == 0)
			unameValidation(argc, argv);
		else
			printf("Unknown command\n");
	}else
		printf("Usage: %s <argument>\n", argv[0]);
	return 0;
}