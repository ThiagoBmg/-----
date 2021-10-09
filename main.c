#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./config/options.c"

int show_movimentacoes_types(){
  int user_input = 0; 

  for(int i =1; i < TIPO_MOVIMENTACAO_N+1 ; i++)
    printf("%d - %s \n", i ,TIPO_MOVIMENTACAO[i-1]);
  
  scanf("%d", &user_input);

  printf("A opcao selecionada foi: %s \n", TIPO_MOVIMENTACAO[user_input-1]);

  return user_input-1;
}

int show_menu_options(){
   int user_input = 0; 

  for(int i =1; i < OPCOES_N+1 ; i++)
    printf("%d - %s \n", i ,MENU_OPTIONS[i-1]);
  
  scanf("%d", &user_input);

  printf("A opcao selecionada foi: %s \n", MENU_OPTIONS[user_input-1]);

  return user_input-1;
}


void do_something(){
    printf("Beleza, so não foi printado nada por isto \n\n");
}

void menu(){
  // responsável por renderizar o menu do app
  int *USER_INPUT = 0 ;

  printf("Ola, seja bem vindo ao Gerenciador Financeiro \n");
  printf("Escolha uma das opcoes para prosseguir: \n\n");
  
  int input = show_menu_options();

  system("cls");
  /* routes */
  if(input==0)
    return do_something();
  if(input==1)

    return do_something();
  if(input==2)
    return do_something();
  else
    printf("Opcao nao encontrata, tente novamente \n");
    return menu();
}

int main(void) {
  menu();
  return 0;
}
