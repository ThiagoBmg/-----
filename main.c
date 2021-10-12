#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -o app .\main.c ; .\app.exe
#include "./config/menu.c"
#include "./models/usuario.c"

void main(void) {
  system("cls");

  // criando diretorio de storage
  system("mkdir storage");

  // checando se existe um usuário cadastrado.
  int result = user_validate();

  if(result == 0)
    return user_create();
    
  return menu();
}
