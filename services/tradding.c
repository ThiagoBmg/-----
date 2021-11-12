#if defined(__MINGW32__) || defined(_MSC_VER)
    #include <Windows.h>
 #else
    #include <unistd.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#include "../utils/clear_command.h"
#include "../utils/printf.config.h"

#define default_delay_ 2 // secs

int randInRange(int min, int max)
{
  return min + (int) (rand() / (double) (RAND_MAX + 1) * (max - min + 1));
}

struct tradding
{
    int initial_value;
    int final_value;
    int max_rounds;
    int op_win;
    int op_loss;
};


void run_tradding()
{
 limpar_tela();
    print("Olá, seja bem vindo ao modelo de Tradding", "green");
    print("Para tornar sua expericencia melhor, siga as instruções a seguir :)", "");
    
    struct tradding lancamento; 

    print("\nDigite o valor que deseja investir...", "green");
    scanf("%ld", &lancamento.initial_value);

    print("\nDigite a quantidade de operações que deseja realizar...", "green");
    scanf("%ld", &lancamento.max_rounds);

    lancamento.op_win =0; 
    lancamento.op_loss =0; 

    limpar_tela();
    print("Iniciando simulação de bot...", "alert");

    for(int i=0; i<lancamento.max_rounds; i++){
        // get current date
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        char s[64];
        assert(strftime(s, sizeof(s), "%c", tm));

        // sort operation status 
        int result = randInRange(0,1);
        printf("%s - operacao %ld \n\n", s,i+1);

        if(result){
            print("ganho", "green");
            lancamento.op_win++;
        }
        if(!result){
            print("perdido", "alert"); 
            lancamento.op_loss++;
        }
        sleep(default_delay_);
    }

    print("Sessão finalizada, foi um prazer simular esta ação para você :)", "green");
    return;
}

// dev mode only 
//int main(void)
//{
//    return 0;
//}