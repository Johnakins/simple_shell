#include "chell.h"
#include <unistd.h>

void forkexe(char *arstr[], char *envp[]) {
    pid_t child_pid;
    int status = 0;

    child_pid = fork();
    if (child_pid < 0) {
        perror("Error: fork issue");
        return;
    }

    if (child_pid == 0) {
        if (execve(arstr[0], arstr, envp) == -1) {
            perror("./shell: No such file or directory\n");
            exit(EXIT_FAILURE); // Terminate the child process on execv error
        }
    } else {
        wait(&status); // Pass the address of status to wait
    }
}

