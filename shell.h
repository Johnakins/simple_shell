#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
void run_shell(void);
char *read_input(void);
void execute_command(char *command, char **args);
void env_builtin(void);
#endif
