char* step_01_mov_types(){
    system("cls");
    printf("Selecione o tipo do lancamento a ser realizado: \n\n");
    return show_movimentacoes_types();
}

long double step_02_valor(){
    system("cls");
    printf("Agora digite o valor: \n");

    long double v=0; 
    scanf("%lf", &v);
    return v;
}

char* step_03_descricao(){
    system("cls");
    printf("Qual a descricao da movimentacao? \n");
    return show_movimentacoes_descricao();
}

void step_04_confirmacao(char *mov_type,long double mov_valor, char *mov_descricao){
    system("cls");
    printf("<< Lancamento a ser realizado >> \n");
    printf("Tipo da Movimentacao: %s \n", mov_type);
    printf("Valor da Movimentacao: %.2lf \n", mov_valor);
    printf("Descricao da Movimentacao: %s \n\n", mov_descricao);
    
    printf("Deseja confirmar este lancamento?\n1- Sim\n2- Nao\n\n");
    int user_input = 0;
    scanf("%d", &user_input);

    if(user_input==1){
        system("cls");
        novo_lancamento(mov_type, mov_valor,mov_descricao);
        printf("Confirmado com sucesso :)\n\n");
        return recursao_menu();
    }else if(user_input==2){
        system("cls");
        printf("Ok, lancamento descartado. \n\n");
        return recursao_menu();
    }
    else{
        printf("Nao entendi sua resposta, tente novamente...\n");
        return step_04_confirmacao(mov_type,mov_valor,mov_descricao);
    }
}

void lancamento_workflow(){
    char *mov_type = step_01_mov_types();
    long double mov_valor = step_02_valor();
    char *mov_descricao = step_03_descricao();
    step_04_confirmacao(mov_type, mov_valor,mov_descricao);
}