#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#ifndef RM_H
#define RM_H
int s_rm(int argc, char *argv[]);
int rmDirectory(const char *dir_path);

#endif//RM_H