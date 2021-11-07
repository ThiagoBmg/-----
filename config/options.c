#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../models/carteira.c"
#include "../utils/clear_command.h"

/* OPÇÕES DE DESCRIÇÃO  */
char* show_movimentacoes_descricao(){
  int user_input = 0;

  for(int i=1; i< DESCRICAO_N+1; i++)
    printf("%d - %s \n", i ,IN_OUT[i-1]);
  
  scanf("%d", &user_input);

  if(user_input > DESCRICAO_N  || user_input == 0){
    //printf("Ops, a opção selecionada nao existe. Tente novamente com uma opção valida\n");
    return "- Sem Descricao -";
  }else{
    // printf("A opcao selecionada foi: %s \n", TIPO_MOVIMENTACAO[user_input-1]);
    return IN_OUT[user_input-1];
  }

}

/* OPÇÕES TIPO DE MOVIMENTAÇÕES */
char* show_movimentacoes_types(){
  int user_input = 0; 

  for(int i =1; i < TIPO_MOVIMENTACAO_N+1 ; i++)
    printf("%d - %s \n", i ,TIPO_MOVIMENTACAO[i-1]);
  
  scanf("%d", &user_input);

  if(user_input > TIPO_MOVIMENTACAO_N  || user_input == 0){
    //printf("Ops, a opção selecionada nao existe. Tente novamente com uma opção valida\n");
    return "- Sem Tipo -";
  }else{
    // printf("A opcao selecionada foi: %s \n", TIPO_MOVIMENTACAO[user_input-1]);
    return TIPO_MOVIMENTACAO[user_input-1];
  }
}

/* OPÇÕES DO MENU */
void show_menu_options(){
  int user_input = 0; 
  printf("Escolha uma das opcoes para prosseguir: \n\n");

  for(int i =1; i < OPCOES_N+1 ; i++)
    printf("%d - %s \n", i ,MENU_OPTIONS[i-1]);
  
  scanf("%d", &user_input);
  
  limpar_tela();
  
  router_menu(user_input-1);
  return;
}