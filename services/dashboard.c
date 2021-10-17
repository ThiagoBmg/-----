// script responsável por gerar os relatórios desejados
// TODO: corrigir bug com o contexto no return em create_context
#define TEMPLATE_PATH "./templates/dashboard.html"
#define LANCAMENTOS_PATH "./storage/lancamentos.txt"
#define OUT_PATH "./reports/"

#include <stdio.h>
#include <string.h>
#include <string.h>
#include "../utils/string_replace.c"

#define MAX_B 2000

// Modelo do template que sera gerado
//    <tr>
//      <td>Transporte</td>
//      <td>R$20</td>
//      <td>10-02-2020</td>
//      <td>Loren Ipsun</td>
//    </tr>

FILE * get_template(char * url){
    FILE * file;
    file = fopen(url, "r+");
    return file;
}

char * create_context(FILE * lancamentos){
    char lancamentosLine[MAX_B],context[MAX_B];
 
    // para cada lancamento iremos criar um template e substituir alguns pontos... 
    while(!feof(lancamentos)){
        fgets(lancamentosLine, 1000, lancamentos);
        int init_size = strlen(lancamentosLine);
        char * mov_type,  * valor, * data, * descricao; 
        char tag_[] = " <tr> <td>{{%%mov_type%%}}</td> <td>{{%%valor%%}}</td> <td>{{%%data%%}}</td> <td>{{%%descricao%%}}</td></tr>";
        
        // buscando os lancamentos
        int count = 0;
        char delim[] = ",";
        char *ptr = strtok(lancamentosLine, delim);
        mov_type = ptr;
        while (ptr != NULL){
		    ptr = strtok(NULL, delim);
            if(count==0)
                valor = ptr;
            if(count==1)
                data = ptr;
            if(count==2)
                descricao = ptr;    
            count++;
        }

        // identificando que não existem mais registros validos para serem renderizados
        if(!valor) return "ok, necessita e concerto... rsrsrs";
        //if(!valor) return context;
        //printf("%s",context);
    
        // substituindo os valores no template da tabela 
        string_replace(tag_, MAX_B, "{{%%mov_type%%}}", mov_type);
        string_replace(tag_, MAX_B, "{{%%valor%%}}", valor);
        string_replace(tag_, MAX_B, "{{%%data%%}}", data);
        string_replace(tag_, MAX_B, "{{%%descricao%%}}", descricao);

        // concatenando o texto ao que será retornado 
        strcat( context, tag_);
    }
}


char * read_template(FILE * template){
    // lendo e escrevendo novo arquivo html 
    char * response;
    char htmlTemplateLine[MAX_B];
    
    do{
        fgets(htmlTemplateLine, MAX_B, template);
        strcat(response,htmlTemplateLine);
    }
    while(!feof(template));

    return response;
}

int main(void){
    FILE * lancamentos = get_template(LANCAMENTOS_PATH);
    FILE * template = get_template(TEMPLATE_PATH);
    char * custom_template_string = create_context(lancamentos);
    char * html_file_string = read_template(template);
   // printf("%s", custom_template_string);
}
