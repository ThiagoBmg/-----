#define LANCAMENTOS_PATH "./storage/lancamentos.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/string_replace.h"
#include "../utils/printf.config.h"

int carteira_service()
{   
   // FILE * lancamentos = fopen(LANCAMENTOS_PATH, "r+");
   // if(lancamentos == NULL){
   //     print("Não existem lançamentos para serem renderizados...", "alert");
   //     return 0;
   // }
   int i = is_valid();

   if(i){
    int qtd = qtd_lancamentos();
	
   // int valor = valor_guardado();
    print("<< Minha Carteira >>", "green");
    printf("Total de lancamentos: %ld\n", qtd);

    int valor = valor_guardado();
    printf("Valor Total: %ld\n\n", valor);

    return 0;
   }else{
       print("Não existe uma carteira para ser análisada, tente realizar um lanãmento antes de executar esta ação...", "alert");
       return 0;
   }

}
