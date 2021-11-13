#include <stdio.h>
#include <stdlib.h>

#include "../config/options.c"
#include "../config/router.c"
#include "../utils/clear_command.h"

void menu()
{
  limpar_tela();
  printf("Ola, seja bem vindo ao Gerenciador Financeiro\n");
  
  show_menu_options();
  return;
}

int recursao_menu()
{
    int user_input=0; 
    printf("Deseja realizar uma nova acao?\n\33[32m 1\33[0;0m - Sim\n\33[32m 2\33[0;0m - Nao\n\n");

    scanf("%d", &user_input);
    limpar_tela();

    if(user_input==1){
        printf("Certo...\n");
        show_menu_options();
        return 1;
    }
    else if(user_input==2){
        printf("Ok\nAte Logo! :)\n");
        exit(EXIT_SUCCESS);
    }
    else{
       // printf("Nao entendi sua resposta, tente novamente...\n"); 
        recursao_menu(); 
        return 1;
    }
}