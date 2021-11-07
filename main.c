#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./config/menu.c"
#include "./models/usuario.c"
#include "./utils/clear_command.h"

void main(void){
  // criando diretorio de storage
  system("mkdir storage");
  system("mkdir reports");
  limpar_tela();
  // checando se existe um usuário cadastrado.
  int result = user_validate();

  if(result == 0){
    user_create();
  }
  else{
    menu();
  }     
}