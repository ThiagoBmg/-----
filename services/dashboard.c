// script responsável por gerar os relatórios desejados
#define TEMPLATE_PATH "./templates/dashboard.html"
#define LANCAMENTOS_PATH "./storage/lancamentos.txt"
#define OUTPUT_PATH "./reports/"
#define MAX_B 2000

#include <stdio.h>
#include <string.h>

#include "../utils/string_replace.h"

// TODO: validar se existe lançamento antes de gerar o relatório

// variavel global responsável por armazenar 
// o contexto personalizado criado pela 
// função create_context e definido em define_custom_context
char * context_temp;

// responsável por realizar a leitura de um arquivo de texto
// [args] url -> str = caminho para o arquivo que deseja realizar a leitura
// [return] FILE -> retorna o arquivo para manipulação 
FILE * get_template(char * url)
{
    FILE * file;
    file = fopen(url, "r+");
    return file;
}

void define_custom_context(FILE * template)
{
    char templateLine[MAX_B];

    FILE *file = fopen("./reports/meu_relatorio.html", "w");

    while(!feof(template)){
        fgets(templateLine, MAX_B, template);
        string_replace(templateLine, MAX_B, "{{STR_REPLACE}}", context_temp);
        printf("html line -> : %s", templateLine);
        fprintf(file, templateLine);
    }
    fclose(file);
    
    return; 
}

// responsável por criar o contexto de lançamentos
// e realizar a leitura dos dados do arquivo txt que contem os lançamentos
// [args] lancamentos -> FILE = arquivo de lançamentos já aberto 
// [return]  define_custom_context -> retorna a função que ira definir o contexto customizado após coletar todos os dados do arquivo
char * create_context(FILE * lancamentos)
{
    char lancamentosLine[MAX_B];
    context_temp = (char *)malloc(10*sizeof(char)); 
    // para cada lancamento ... 
    while(!feof(lancamentos)){
        fgets(lancamentosLine, MAX_B, lancamentos);
        int init_size = strlen(lancamentosLine);
        char * mov_type,  * valor, * data, * descricao; 
        char tag_[] = "<tr><td>{{%%mov_type%%}}</td><td>{{%%valor%%}}</td><td>{{%%data%%}}</td><td>{{%%descricao%%}}</td></tr>";
        
        // buscando os lancamentos
        int current_line = 0;
        char *ptr = strtok(lancamentosLine, ",");

        // guardando valores de acordo com sua posição
        mov_type = ptr;
        do{ ptr = strtok(NULL, ",");
            if(current_line==0)
                valor = ptr;
            if(current_line==1)
                data = ptr;
            if(current_line==2)
                descricao = ptr;    
            current_line++;
        }while (ptr != NULL);

        // identificando que não existem mais registros validos para serem renderizados
        if(!valor) {
            //printf("%s", custom_context);
            //define_custom_context(context_temp);
            return "";
        }

        // substituindo os valores no template html com os valores do arquivo de lancamentos
        string_replace(tag_, MAX_B, "{{%%mov_type%%}}", mov_type);
        string_replace(tag_, MAX_B, "{{%%valor%%}}", valor);
        string_replace(tag_, MAX_B, "{{%%data%%}}", data);
        string_replace(tag_, MAX_B, "{{%%descricao%%}}", descricao);
        // concatenando o texto em uma string temporaria 
        strcat( context_temp, tag_);
    }
    return "done";
}

// responsável por ler e retornar o template do relatório em html
// [args] template -> FILE = arquivo de template do relatório em HTML já aberto
// [return] response -> str = retorna o template em html convertido para string
char * read_template(FILE * template)
{
    char * response;
    char htmlTemplateLine[MAX_B];
    
    do{
        fgets(htmlTemplateLine, MAX_B, template);
        strcat(response,htmlTemplateLine);
    }
    while(!feof(template));

    return response;
}

int dashboard_service()
{
    FILE * lancamentos = get_template(LANCAMENTOS_PATH);
    FILE * template = get_template(TEMPLATE_PATH);
    create_context(lancamentos); // função que cria e atribui o contexto customizado a uma string global -> printf("%s", custom_context);
    define_custom_context(template); // função que substitui no template o contexto criado anteriormente
    recursao_menu();  // é necessário remover em um cenário de testes
    return 0;
}

/*  DEV MODE ONLY  */
//int main()
//{
//    dashboard_service();
//    return 0;
//} 