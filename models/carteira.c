#include <stdio.h>
#include <time.h>
#include <assert.h>
#define CARTEIRA_FILE "./storage/lancamentos.txt"

/* OPÇÕES TIPO DE MOVIMENTAÇÕES */
//char *tipo ="" , *valor = "" , *descricao = "", *data=""; 
#define TIPO_MOVIMENTACAO_N  5
#define OPCOES_N  3
#define DESCRICAO_N 2
char TIPO_MOVIMENTACAO[TIPO_MOVIMENTACAO_N][20] = {"Moradia","Estudos", "Transporte", "Alimentacao", "Trabalho"};; 
char MENU_OPTIONS[OPCOES_N][20] =  {"Novo Lancamento","Gerar Relatorio","Sobre Este App"}; 
char IN_OUT[DESCRICAO_N][10] = {"Entrada", "Saida"};
// TODO: adicionar opções de manipulação das informações + validações aqui


int novo_lancamento(char *mov_type,long double mov_valor, char *mov_descricao){
   FILE *data = fopen(CARTEIRA_FILE, "a");
   fprintf(data, mov_type);
   fprintf(data, ",");

   char output[50];
   snprintf(output, 50, "%Lf", mov_valor);
   fprintf(data, output);
   fprintf(data, ",");

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    
    assert(strftime(s, sizeof(s), "%c", tm));
    fprintf(data, s);
    fprintf(data, ",");

   fprintf(data, mov_descricao);
   fprintf(data, "\n");
   fclose(data);
   return 0;
}