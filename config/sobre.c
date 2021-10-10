void show_sobre(){
    char *about = "Desenvolvido por Thiago Braga Martins Gomes [Matricula 22121064-4]\n\n";    
    char *repo= "Repositorio https://github.com/ThiagoBmg/gerenciador_fin_FEI\n\n";
    char *text= "Acesse o arquivo README.md na raiz do projeto para mais informacoes.\n\n";
    
    printf("%s%s%s \n\n", about,repo,text);
    return recursao_menu();
}