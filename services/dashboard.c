// script responsável por gerar os relatórios desejados
// TODO: corrigir bug com o contexto no return em create_context
// TODO: validar melhor metodo para atribuir valor a uma string 
#define TEMPLATE_PATH "./templates/dashboard.html"
#define LANCAMENTOS_PATH "./storage/lancamentos.txt"
#define OUTPUT_PATH "./reports/"
#define MAX_B 2000

#include <stdio.h>
#include <string.h>
#include "../utils/string_replace.c"

// variavel global responsável por armazenar 
// o contexto personalizado criado pela 
// função create_context e definido em define_custom_context
char custom_context[MAX_B];

FILE * get_template(char * url)
{
    // responsável por realizar a leitura de um arquivo de texto
    // [args] url -> str = caminho para o arquivo que deseja realizar a leitura
    // [return] FILE -> retorna o arquivo para manipulação 
    FILE * file;
    file = fopen(url, "r+");
    return file;
}

char * define_custom_context(char str[MAX_B])
{
    // responsável por definir uma string com o template customizado, de acordo com os lançamentos
    // args str -> str = string contendo o template customizado
    // return strcat -> retorna a concatenação de uma string vazia + o template customizado
    return strcat(custom_context, str);
}

char * create_context(FILE * lancamentos)
{
    // responsável por criar o contexto de lançamentos
    // e realizar a leitura dos dados do arquivo txt que contem os lançamentos
    // [args] lancamentos -> FILE = arquivo de lançamentos já aberto 
    // [return]  define_custom_context -> retorna a função que ira definir o contexto customizado após coletar todos os dados do arquivo
    char lancamentosLine[MAX_B] , context_temp[MAX_B];
    // para cada lancamento ... 
    while(!feof(lancamentos)){
        fgets(lancamentosLine, MAX_B, lancamentos);
        int init_size = strlen(lancamentosLine);
        char * mov_type,  * valor, * data, * descricao; 
        char tag_[] = " <tr> <td>{{%%mov_type%%}}</td> <td>{{%%valor%%}}</td> <td>{{%%data%%}}</td> <td>{{%%descricao%%}}</td></tr>";
        
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
        if(!valor) return define_custom_context(context_temp);
        
        // substituindo os valores no template html com os valores do arquivo de lancamentos
        string_replace(tag_, MAX_B, "{{%%mov_type%%}}", mov_type);
        string_replace(tag_, MAX_B, "{{%%valor%%}}", valor);
        string_replace(tag_, MAX_B, "{{%%data%%}}", data);
        string_replace(tag_, MAX_B, "{{%%descricao%%}}", descricao);

        // concatenando o texto em uma string temporaria 
        strcat( context_temp, tag_);
    }
}

char * read_template(FILE * template)
{
    // responsável por ler e retornar o template do relatório em html
    // [args] template -> FILE = arquivo de template do relatório em HTML já aberto
    // [return] response -> str = retorna o template em html convertido para string
    char * response;
    char htmlTemplateLine[MAX_B];
    
    do{
        fgets(htmlTemplateLine, MAX_B, template);
        strcat(response,htmlTemplateLine);
    }
    while(!feof(template));

    return response;
}

int main(void)
{
    FILE * lancamentos = get_template(LANCAMENTOS_PATH);
    FILE * template = get_template(TEMPLATE_PATH);
    char * html_file_string = read_template(template);
    create_context(lancamentos); // função que cria e atribui o contexto customizado a uma string global -> printf("%s", custom_context);
}
