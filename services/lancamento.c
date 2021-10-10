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

void lancamento_workflow(){
    char *mov_type = step_01_mov_types();
    long double mov_valor = step_02_valor();
    
    printf("FINAL DO FLUXO \n");
    printf("%s \n", mov_type);
    printf("%.2lf \n\n", mov_valor);
}