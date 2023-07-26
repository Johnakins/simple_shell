#ifndef SHELL_H
#define SHELL_H
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
void execute_command(char *const args[]);
char *read_input();
char **tokenize_input(char *input);
extern char **environ;
#endif
