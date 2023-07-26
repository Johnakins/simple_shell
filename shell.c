#include "shell.h"

void run_shell(void)
{
    char *buffer;
    char *command;

    while (1)
    {
        printf("#cisfun$ ");
        buffer = read_input();
        command = strtok(buffer, " \n");
        execute_command(command, NULL);
        free(buffer);
    }
}

char *read_input(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters_read;

    characters_read = getline(&buffer, &bufsize, stdin);
    if (characters_read == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }
    return buffer;
}

void execute_command(char *command, char **args)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        execve(command, args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(&status);
    }
}

