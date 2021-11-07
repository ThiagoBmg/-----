#if !defined CLEAR_COMMAND_H
    #define CLEAR_COMMAND_H 
    #if defined(__MINGW32__) || defined(_MSC_VER)
        #define limpar_tela() system("cls")
    #else
        #define limpar_tela() system("clear")
    #endif
#endif