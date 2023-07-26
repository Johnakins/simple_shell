#include "chell.h"

char **chstrtok(char *str) {
    char **arst, *pars;
    int i = 0, j = 0, num_tokens = 0;

   
    pars = strtok(str, " ");
    while (pars != NULL) {
        num_tokens++;
        pars = strtok(NULL, " ");
    }

    arst = malloc((num_tokens + 1) * sizeof(char *));
    if (arst == NULL) {
        perror("can't allocate space");
        exit(1);
    }

    pars = strtok(str, " ");
    while (pars != NULL) {
        int token_length = strlen(pars);
        arst[i] = malloc((token_length + 1) * sizeof(char));
        if (arst[i] == NULL) {
            perror("can't allocate space");
            exit(1);
        }
        
        while (pars[j]) {
            if (pars[j] == '\n')
                pars[j] = '\0';
            j++;
        }

        strcpy(arst[i], pars);
        i++;
        j = 0;
        pars = strtok(NULL, " ");
    }

    arst[i] = NULL;
    return arst;
}

