#ifndef SHELL_H
#define SHELL_H
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
/*constant variables*/
#define OUTTER_CMD 1
#define INNER_CMD 2
#define PATH_CMD 3
#define INV_CMD -1
typedef struct func_map
{
	char *cmd_name;
	void (*func)(char **cmd);
} func_map;


extern char **environ;
extern char *line;
extern char *shellname;
extern int status;
extern char **command;

/*builtin*/
void env(char **cmd);
void quit(char **cmd);

/*utility*/
int parse_cmd(char *cmd);
void execute_command(char **tok_cmd, int typ_cmd, char *shellname);
char *_getenv(char *n);
void (*get_func(char *cmd))(char **);
char *path_check(char *cmd);

/*helper_1 helper_2, add_help*/
char **tokenizer(char *input, char *delimiter);
void _print(char *string, int srm);
void _strcpy(char *src, char *des);
void rm_newline(char *string);
int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
void *_realloc(void *p, unsigned int o_size, unsigned int n_size);
void handler(int sign);
void rm_comment(char *input);
char *_strtok_r(char *str, const char *delim, char **ptr);
char *_strcat(char *dest, char *src);
int _strspn(const char *s1, const char *s2);
int _strcspn(const char *s1, const char *s2);
const char *_strchr(const char *str, char c);
unsigned int min(unsigned int a, unsigned int b);
int _atoi(char *str);

extern void ini_tializer(char **current_command, int typ_command, char *shellname);
extern void not_active(void);
#endif
