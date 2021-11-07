
#include <stdio.h>
#include <stdlib.h>

#include "../config/options.c"
#include "../config/router.c"
#include "../utils/clear_command.h"

void menu(){
  limpar_tela();
  printf("Ola, seja bem vindo ao Gerenciador Financeiro\n");
  
  show_menu_options();
  return;
  // TODO: validar sistema operacional para validar o uso de cls ou clear
}

int recursao_menu(){
    int user_input=0; 
    printf("Deseja realizar uma nova acao? \n1- Sim\n2- Nao \n\n");

    scanf("%d", &user_input);
    limpar_tela();

    if(user_input==1){
        printf("Certo...\n");
        show_menu_options();
        return 1;
    }
    else if(user_input==2){
        printf("Ok\nAte Logo! :)\n");
        exit(0);
    }
    else{
        printf("Nao entendi sua resposta, tente novamente...\n"); 
        recursao_menu(); 
        return 1;
    }
}