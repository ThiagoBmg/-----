#include "../utils/string_replace.c"
#include <stdio.h>
#include <stdlib.h>

void test_string_replace(){
    char string_test[] = "STRING REPLACE TESTE -> FAIL";
    string_replace(string_test, sizeof(string_test)+sizeof("OK :)")-sizeof("FAIL"), "FAIL", "OK :)");
    printf("%s", string_test);
    return exit(1);
}


int main(void){
    test_string_replace();
    return 0;
}