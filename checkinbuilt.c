#include "chell.h"

int checkinbuilt(char *str) {
    char **arr;
    int i = 0;
    char *username;

    arr = malloc(sizeof(char *) * 3);
    if (arr == NULL)
        return 0;

    arr[0] = "cd";
    arr[1] = "exit";
    arr[2] = "hello";

    for (i = 0; i < 3; i++) {
        if (strcmp(arr[i], str) == 0)
            break;
    }

    switch (i) {
        case 0:
            chdir(str);
            free(arr);
            return 1;
        case 1:
            free(arr);
            exit(0);
        case 2:
            username = getenv("USER"); // Use "USER" instead of "HOSTNAME" to get the username
            printf("Hello %s\n", username);
            free(arr);
            return 1;
        default:
            free(arr);
            return 0;
    }

    return 0;
}

