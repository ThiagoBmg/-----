#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* string_replace(char* source, size_t sourceSize, char* substring, char* with) {
    char* substring_source = strstr(source, substring);
    if (substring_source == NULL) {
        return NULL;
    }
 
    if (sourceSize < strlen(source) + (strlen(with) - strlen(substring)) + 1) {
        printf("Buffer size is too small\n");
        return NULL;
    }
 
    memmove(
        substring_source + strlen(with),
        substring_source + strlen(substring),
        strlen(substring_source) - strlen(substring) + 1
    );
 
    memcpy(substring_source, with, strlen(with));
    return substring_source + strlen(with);
}