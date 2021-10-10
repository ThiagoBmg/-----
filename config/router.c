// TODO: declarar possiveis caminhos do fluxo aqui. 
#include "sobre.c"
#include "../services/lancamento.c"

void router_menu(int *input){
  //"Novo Lancamento"
  if(input==0)
    return lancamento_workflow();
  //"Gerar Relatorio"
  if(input==1)
    return 0;
  //"Sobre Este App"
  if(input==2)
    return show_sobre();
  // rota não encontrada
  else{
    printf("Nao entendi sua resposta, tente novamente...\n");
    return menu();
  }
}
