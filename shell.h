#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_INPUT 1000
#define MAX_ARGS 100
void execute_cmd(char **argv);
void exit_shell();
char *locate_cmd(char *command);
#endif
