#define LANCAMENTOS_PATH "./storage/lancamentos.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/string_replace.h"
#include "../utils/printf.config.h"
//#include "../models/carteira.c" 

char * get_wallet(FILE * lancamentos)
{
    char * context_temp = (char *) calloc(MAX_B , sizeof(char)); 
    
    char lancamentosLine[MAX_B];
    // para cada lancamento ... 
    while(!feof(lancamentos)){
        fgets(lancamentosLine, MAX_B, lancamentos);
        char * mov_type,  * valor, * data, * descricao; 
       
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
            //free(lancamentos);
           return context_temp;
        }
    }
    return "done";
}

int carteira_service()
{   
   // FILE * lancamentos = fopen(LANCAMENTOS_PATH, "r+");
   // if(lancamentos == NULL){
   //     print("Não existem lançamentos para serem renderizados...", "alert");
   //     return 0;
   // }

    int qtd = qtd_lancamentos();
	
   // int valor = valor_guardado();
    print("<< Minha Carteira >>", "green");
    printf("Total de lancamentos: %ld\n", qtd);

    int valor = valor_guardado();
    printf("Valor Total: %ld\n\n", valor);

    return 0;
}
