#include "../utils/string_replace.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_string_replace(){
    char string_test[] = "STRING REPLACE TESTE -> FAIL";
    char string_ok[] = "STRING REPLACE TESTE -> OK :)";
    string_replace(string_test,sizeof(string_ok), "FAIL", "OK :)");

    int result = strcmp(string_test, string_ok);
    printf("%s\n", string_test);
    if(!result == 0)
        return  exit(1);
    return;
}


int main(void){
    test_string_replace();
    return 0;
}