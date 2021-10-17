// script responsável por gerar os relatórios desejados

#define TEMPLATE_PATH "./templates/dashboard.html"
#define LANCAMENTOS_PATH "./storage/lancamentos.txt"
#define OUT_PATH "./reports/"

#include <stdio.h>
#include <string.h>
#include <string.h>
#include "../utils/string_replace.c"

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

void create_custom_template(FILE * lancamentos){
    char lancamentosLine[10000], templateLine[10000];
    char context[12222];
 
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
        while (ptr != NULL)
	    {
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
        if(!valor){
            printf("%s", context);
            return;
        }
        
        // substituindo os valores no template da tabela 
        string_replace(tag_, 1000, "{{%%mov_type%%}}", mov_type);
        string_replace(tag_, 1000, "{{%%valor%%}}", valor);
        string_replace(tag_, 1000, "{{%%data%%}}", data);
        string_replace(tag_, 1000, "{{%%descricao%%}}", descricao);

        // concatenando o texto ao que será retornado 
        strcat( context, tag_);
       
        //printf("mov type ===%s\n", mov_type);
        //printf("valor type ===%s\n", valor);
        //printf("data type ===%s\n", data);
        //printf("descricao type ===%s\n", descricao);
        //printf("%s\n\n", tag_);
    }
}

int main(void){
   FILE * lancamentos = get_template(LANCAMENTOS_PATH);
   FILE * template = get_template(TEMPLATE_PATH);
   create_custom_template(lancamentos);
}
