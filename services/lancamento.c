#include "../utils/clear_command.h"
#include "../utils/printf.config.h"

char* step_01_mov_types(){
    limpar_tela();
    print("Selecione o tipo do lancamento a ser realizado:", "green");
    return show_movimentacoes_types();
}

long double step_02_valor(){
    limpar_tela();
    print("Agora digite o valor:","green");

    long double v=0; 
    scanf("%Lf", &v);
    return v;
}

char* step_03_descricao(){
    limpar_tela();
    print("Qual a descricao da movimentacao?", "green");
    return show_movimentacoes_descricao();
}

int step_04_confirmacao(char *mov_type,long double mov_valor, char *mov_descricao){
    limpar_tela();
    print("<< Lancamento a ser realizado >>", "green");
    printf("Tipo da Movimentacao: %s \n", mov_type);
    printf("Valor da Movimentacao: %.2Lf \n", mov_valor);
    printf("Descricao da Movimentacao: %s \n\n", mov_descricao);
    
    print("Deseja confirmar este lancamento?", "green");
    printf("\n\33[32m 1\33[0;0m - Sim\n\33[32m 2\33[0;0m - Nao\n\n");

    int user_input = 0;
    scanf("%d", &user_input);

    if(user_input==1){
        limpar_tela();
        novo_lancamento(mov_type, mov_valor,mov_descricao);
        printf("Confirmado com sucesso :)\n\n");
        recursao_menu();
    }else if(user_input==2){
        limpar_tela();
        printf("Ok, lancamento descartado. \n\n");
        recursao_menu();
    }
    else{
        printf("Nao entendi sua resposta, tente novamente...\n");
        step_04_confirmacao(mov_type,mov_valor,mov_descricao);
        return 0;
    }
    // caso tudo ocorra bem retorna true // 1
    return 1;
}

void lancamento_workflow(){
    char *mov_type = step_01_mov_types();
    long double mov_valor = step_02_valor();
    char *mov_descricao = step_03_descricao();
    step_04_confirmacao(mov_type, mov_valor,mov_descricao);
}