#include "chell.h"


int _strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}


char* _strcat(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = (char *)malloc(len1 + len2 + 1);
    if (!result) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char *filechk(char *str) {
    DIR *dir = opendir("/bin/");
    char *temp, *cats = NULL;
    struct dirent *entity;

    if (dir == NULL)
        return NULL;

    
    if (str[0] == '/') {
        cats = (char *)strdup(str);
        closedir(dir);
        return cats;
    }

    entity = readdir(dir);
    while (entity != NULL) {
        temp = entity->d_name;
        if (_strcmp(temp, str) == 0) {
            cats = _strcat("/bin/", str);
            closedir(dir);
            return cats;
        }
        entity = readdir(dir);
    }

    closedir(dir);
    return NULL;
}

