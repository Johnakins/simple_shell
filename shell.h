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
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *str);
char **split_string(const char *str, char delimiter, int *num_tokens);
char **_getenv(char *var);
void _free(char **array);
void execute_command(char *const args[]);
char *read_input();
char **tokenize_input(char *input);
void print_environment(void);
int builtin_exit(void);
char *path_handler(const char *command);

extern char **environ;
#endif
