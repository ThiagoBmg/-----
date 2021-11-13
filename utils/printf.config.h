#include <stdio.h>
#include <stdlib.h>

void print(char * text, char * color){
    char space[4] = "\n\n";

    if(color == "green")
        printf("\33[32m%s\33[0;0m%s", text,space);
    else if(color == "alert")
        printf("\033[41m%s\033[0;0m%s", text, space);
    else{
        printf("%s%s", text, space);
    }
    return; 
}