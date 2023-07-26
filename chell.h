#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>

int checkinbuilt(char *str);
char **chstrtok(char *str);
char *filechk(char *str);
void forkexe(char **arstr, char *envp[]);
int pathchk(char *str);
int _strcmp(const char *s1, const char *s2);


#endif
