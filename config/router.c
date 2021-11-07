#include "sobre.c"
#include "../services/lancamento.c"
#include "../services/dashboard.c"

int router_menu(int *input){
  if(input==0)
    //"Novo Lancamento"
    lancamento_workflow();  
  if(input==1)
    //"Gerar Relatorio"
    dashboard_service();
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
