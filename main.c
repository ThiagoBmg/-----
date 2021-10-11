#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc -o app .\main.c ; .\app.exe
#include "./config/menu.c"
//#include "./models/usuario.c"
#include "./models/usuario.c"

void main(void) {
  system("cls");

  // checando se existe um usuário cadastrado.
  int result = user_validate();

  // criando diretorio de storage, caso ainda não exista 
  system("mkdir storage");

  if(result == 0)
    return user_create();
    
  return menu();
}
