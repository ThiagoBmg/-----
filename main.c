#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./config/menu.c"
#include "./models/usuario.c"

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_input() fflush(stdin)
#define limpar_tela() system("cls")
#else
#include <stdio_ext.h>
#define limpar_input() __fpurge(stdin)
#define limpar_tela() system("clear")
#endif

void main(void) {
  // criando diretorio de storage
  system("mkdir storage");
  limpar_tela();
  // checando se existe um usuário cadastrado.
  int result = user_validate();

  if(result == 0)
    return user_create();
    
  return menu();
}
