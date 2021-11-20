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

#define default_delay_ 1 // secs
#define trading_val 0.3

int randInRange(int min, int max)
{
  return min + (int) (rand() / (double) (RAND_MAX + 1) * (max - min + 1));
}

struct trading
{
    int initial_value;
    int final_value;
    int max_rounds;
    int op_win;
    int op_loss;
};


void run_trading()
{
 limpar_tela();
    print("Olá, seja bem vindo ao modelo de Trading", "green");
    print("Para tornar sua expericencia melhor, siga as instruções a seguir :)", "");
    
    struct trading lancamento; 

    print("Digite o valor que deseja simular...", "green");
    scanf("%ld", &lancamento.initial_value);

    print("\nDigite a quantidade de operações que deseja realizar...", "green");
    scanf("%ld", &lancamento.max_rounds);

    lancamento.op_win =0; 
    lancamento.op_loss =0;
    lancamento.final_value = lancamento.initial_value; 

    limpar_tela();
    print("Iniciando simulação de bot...", "alert");
    sleep(default_delay_);

    for(int i=0; i<lancamento.max_rounds; i++){

        if(lancamento.final_value <= 0){
            print("A operação foi finalizada, pois o valor da operação é menor que zero... considere iniciar uma nova simulação", "alert");
            return;
        }

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
            lancamento.final_value += (lancamento.final_value * trading_val) * 1.5;
            lancamento.op_win++;
        }
        if(!result){
            print("perdido", "alert"); 
            lancamento.final_value -= (lancamento.final_value * trading_val);
            lancamento.op_loss++;
        }
        sleep(default_delay_);
    }

    print("Sessão finalizada", "alert");
    print("Foi um prazer simular esta ação para você :)", "green");
    printf("resultado final: %ld win, %ld loss\n" , lancamento.op_win, lancamento.op_loss);
    printf("valor inicial: %ld\nvalor final: %ld \n\n" , lancamento.initial_value, lancamento.final_value);

    if(lancamento.op_loss < lancamento.op_win)
        print("Você lucrou com esta simulação :)", "green");
    else
        print("Você não obteve um resultado tão bom desta vez... :(", "alert");

    return;
}

// dev mode only 
//int main(void)
//{
//    return 0;
//}