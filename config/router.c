#include "sobre.c"
#include "../services/lancamento.c"
#include "../services/dashboard.c"
#include "../services/trading.c"
#include "../services/carteira.c"

int router_menu(int *input){
  if(input==0)
    //"Novo Lancamento"
    lancamento_workflow();  
  if(input==1)
    //"Minha Carteira"
    carteira_service();	 
  if(input==2)
    //"Gerar Relatorio"
    //system("make dashboard");
    dashboard_service();
  if(input==3)
    // simulação de tradding 
    run_trading();
  if(input==4)
    //"Sobre Este App"
    show_sobre();
  if(input==5)
    // Sair
    exit(EXIT_SUCCESS);
  else{
    // rota não encontrada
    //printf("Nao entendi sua resposta, tente novamente...\n");
    show_menu_options();
    return 0;
  }
  return 1;
}
