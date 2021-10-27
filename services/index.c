#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_tela() system("cls")
#else
#define limpar_tela() system("clear")
#endif


void main(void) {
    printf("sss");
    return 0;
}
