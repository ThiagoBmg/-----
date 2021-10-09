// TODO: declarar possiveis caminhos do fluxo aqui. 
#include "sobre.c"

void router(int *input){
  //"Novo Lancamento"
  if(input==0)
    return 0;
  //"Gerar Relatorio"
  if(input==1)
    return 0;
  //"Sobre Este App"
  if(input==2)
    return show_sobre();
  // rota não encontrada
  else{
    printf("Opcao nao encontrata, tente novamente \n");
    return menu();
  }
}