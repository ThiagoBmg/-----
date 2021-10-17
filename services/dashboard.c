// script responsável por gerar os relatórios desejados

#define template_path "./templates/dashboard.html"
#include <stdio.h>
#include "../utils/string_replace.c"
#define VAR_STR = "{{str}}"

// Modelo do template que sera gerado
//    <tr>
//      <td>Transporte</td>
//      <td>R$20</td>
//      <td>10-02-2020</td>
//      <td>Loren Ipsun</td>
//    </tr>


char get_template(char url){
    FILE * file;
    file = fopen(template_path, "r");
    char singleLIne[10000];

    while(!feof(file)){
        fgets(singleLIne, 1000, file);
        puts(singleLIne);
    }
    return 0;
}

void  build_template(void){
 
    return ;
}

int main(void){
    build_template();
    char te[] = "testando mesmo";
    string_replace(te,sizeof(te), "testando", "ss");
    printf("%s", te);

    //char * teste;
    //teste = get_template(template_path);
   
}
