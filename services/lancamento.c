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

void step_confirmacao(){
    return;
}

void lancamento_workflow(){
    char *mov_type = step_01_mov_types();
    long double mov_valor = step_02_valor();
    char *mov_descricao = step_03_descricao();

    
    printf("FINAL DO FLUXO \n");
    printf("Tipo da Movimentacao: %s \n", mov_type);
    printf("Valor da Movimentacao: %.2lf \n", mov_valor);
    printf("Descricao da Movimentacao: %s \n\n", mov_descricao);
}