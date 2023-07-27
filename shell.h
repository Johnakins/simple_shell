#ifndef SHELL_H
#define SHELL_H
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

void execute_command(char* command, char* program_name);
char *read_input();
char **tokenize_input(char *input);
void print_environment(void);
int builtin_exit(void);
char *path_handler(const char *command);

extern char **environ;
#endif
