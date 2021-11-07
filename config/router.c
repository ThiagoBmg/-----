// TODO: declarar possiveis caminhos do fluxo aqui. 
#include "sobre.c"
#include "../services/lancamento.c"

int router_menu(int *input){
  if(input==0)
    //"Novo Lancamento"
    lancamento_workflow();  
  if(input==1)
    //"Gerar Relatorio"
    return 1;
  if(input==2)
    //"Sobre Este App"
    show_sobre();
  else{
    // rota não encontrada
    printf("Nao entendi sua resposta, tente novamente...\n");
    show_menu_options();
    return 0;
  }
  return 1;
}
