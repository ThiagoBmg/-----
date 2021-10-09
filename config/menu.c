
#include <stdio.h>
#include <stdlib.h>

#include "../config/options.c"
#include "../config/router.c"


void recursao_menu(){
    int user_input=0; 
    printf("Deseja realizar uma nova acao? \n1- Sim\n2- Nao \n\n");

    scanf("%d", &user_input);
    system("cls");

    if(user_input==1){
        printf("Certo...\n");
        return menu();
    }
    else if(user_input==2){
        printf("Ok\nAte Logo! :)\n");
        return;
    }
    else{
        printf("Nao entendi sua resposta, tente novamente...\n");
        return recursao_menu();
    }
}

void menu(){
  printf("Ola, seja bem vindo ao Gerenciador Financeiro \nEscolha uma das opcoes para prosseguir: \n\n");
  
  int input = show_menu_options();

  // TODO: validar sistema operacional para validar o uso de cls ou clear
  system("cls");
  //system("clear");

  router(input);
}