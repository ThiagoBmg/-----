int show_sobre(){
    char *about = "Desenvolvido por Thiago Braga Martins Gomes [Matricula 22121064-4] e Matteo Kozakevic Nardi [Matrícula 22120050-4]\n\n";    
    char *repo= "Repositorio https://github.com/ThiagoBmg/gerenciador_fin_FEI\n\n";
    char *text= "Acesse o arquivo readme.md na raiz do projeto para mais informacoes.\n\n";
    
    printf("%s%s%s \n", about,repo,text);
    recursao_menu();
    return 1;
}