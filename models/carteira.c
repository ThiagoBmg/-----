#include <stdio.h>
#include <time.h>
#include <assert.h>

#include "../utils/printf.config.h"

#define CARTEIRA_FILE "./storage/lancamentos.txt"

/* OPÇÕES TIPO DE MOVIMENTAÇÕES */
#define TIPO_MOVIMENTACAO_N  5
#define OPCOES_N  6
#define DESCRICAO_N 2
char TIPO_MOVIMENTACAO[TIPO_MOVIMENTACAO_N][20] = {"Moradia","Estudos", "Transporte", "Alimentacao", "Trabalho"};; 
char MENU_OPTIONS[OPCOES_N][20] =  {"Novo Lancamento","Minha Carteira", "Gerar Relatorio", "Trading Simulator", "Sobre Este App", "Sair"}; 
char IN_OUT[DESCRICAO_N][10] = {"Entrada", "Saida"};

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

struct lancamento{
	char * mov_type; 
	char * valor;
	char * descricao; 
};

int is_valid(){
   FILE * data = fopen(CARTEIRA_FILE, "r");

   if (!data)
      return 0;
   return 1; 
}


// função que retorna o valor total na carteira do usuário
int valor_guardado(void){
   FILE * data = fopen(CARTEIRA_FILE, "r");

   int value = 0; 
   char line[200]; 
   
   while(!feof(data)){
   	fgets(line,200,data);
	char * ptr = strtok(line, ",");
	ptr = strtok(NULL, ",");
//	ptr = strtok(NULL, ",");
//	printf("valores -> %s", ptr);
	if(ptr != NULL) value += atoi(ptr); 	
   }	
	
   fclose(data);
   return value;
}

// função resposável por retornar o valor total acumulado do usuário
int qtd_lancamentos(void){
   FILE *data = fopen(CARTEIRA_FILE, "r");
   int n_lines = -1;
   char lancamentos[399];	

   while(!feof(data)){
   	fgets(lancamentos, 399 , data);
	n_lines++;
   }

   fclose(data);
   return n_lines;	
}
