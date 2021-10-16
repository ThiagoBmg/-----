// script responsável por gerar os relatórios desejados

#define template_path "../templates/dashboard.html"
#include <stdio.h>

void  build_template(void){
    FILE * file;
    file = fopen(template_path, "r");
    char my_s[2000]; 
    int NUM_CHARS;
    while (fgets(my_s, NUM_CHARS ,file)){
        printf("%10s", my_s);
    }
    return ;
}

int main(void){
    build_template();
    printf("teste");
}
