// script responsável por gerar os relatórios desejados
#define TEMPLATE_PATH "./templates/dashboard.html"
#define LANCAMENTOS_PATH "./storage/lancamentos.txt"
#define OUTPUT_PATH "./reports/"
#define LIMIT 5000
#define MAX_B 10*LIMIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/string_replace.h"

// TODO: validar se existe lançamento antes de gerar o relatório

void define_custom_context(FILE * template, char * custom)
{
    FILE *file = fopen("./reports/meu_relatorio.html", "w+");
    char templateLine[MAX_B];
    while(!feof(template)){
        fgets(templateLine, MAX_B, template);
        string_replace(templateLine, MAX_B, "{{STR_REPLACE}}", custom);
        fprintf(file, templateLine);
    }
    fclose(file);
    printf("Relatório gerado com sucesso, uma versão atualizada do relatório foi disponibilizada no diretório ./reports/meu_relatorio.html \n\n");
    return; 
}

// responsável por criar o contexto de lançamentos
// e realizar a leitura dos dados do arquivo txt que contem os lançamentos
// [args] lancamentos -> FILE = arquivo de lançamentos já aberto 
// [return]  define_custom_context -> retorna a função que ira definir o contexto customizado após coletar todos os dados do arquivo
char * create_context(FILE * lancamentos)
{
    char * context_temp = (char *) calloc(MAX_B , sizeof(char)); 

    char lancamentosLine[MAX_B];
    // para cada lancamento ... 
    while(!feof(lancamentos)){
        fgets(lancamentosLine, MAX_B, lancamentos);
        char * mov_type,  * valor, * data, * descricao; 
        char tag_[] = "<tr><td>{{%%mov_type%%}}</td><td>{{%%valor%%}}</td><td>{{%%data%%}}</td><td>{{%%descricao%%}}</td></tr>";
        
        // buscando os lancamentos
        int current_line = 0;
        char *ptr = strtok(lancamentosLine, ",");

        // guardando valores de acordo com sua posição
        mov_type = ptr;
        do
        { 
            ptr = strtok(NULL, ",");
            if(current_line==0)
                valor = ptr;
            if(current_line==1)
                data = ptr;
            if(current_line==2)
                descricao = ptr;    
            current_line++;
        }
        while (ptr != NULL);

        // identificando que não existem mais registros validos para serem renderizados
        if(!valor) {
            free(lancamentos);
           return context_temp;
        }

        // substituindo os valores no template html com os valores do arquivo de lancamentos
        string_replace(tag_, MAX_B, "{{%%mov_type%%}}", mov_type);
        string_replace(tag_, MAX_B, "{{%%valor%%}}", valor);
        string_replace(tag_, MAX_B, "{{%%data%%}}", data);
        string_replace(tag_, MAX_B, "{{%%descricao%%}}", descricao);

        // concatenando o texto em uma string temporaria 
        strcat(context_temp, tag_);
    }
    return "done";
}

int dashboard_service()
{   
    FILE * lancamentos = fopen(LANCAMENTOS_PATH, "r+");
    if(lancamentos == NULL){
        //printf("\33[32m teste \33[0;0m");
        printf("\033[41m Não existem lançamentos para serem renderizados... \033[0;0m\n\n");
        return 0;
    }

    FILE * template = fopen(TEMPLATE_PATH, "r+");
    char * custom_template = create_context(lancamentos); 
    //printf("%s", custom_template);
    
    define_custom_context(template, custom_template);
    //recursao_menu();
    return 0;
}

//int main()
//{
//    dashboard_service();
//    return 0;
//} 