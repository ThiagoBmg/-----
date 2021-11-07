all: 
	#!/bin/sh
	echo "Removendo versões anteriores"
	rm -rf app.exe ;
	echo "Compilando o projeto..."	
	gcc -o app.exe main.c -Wreturn-type -ferror-limit=2000 -Werror -Wmain-return-type -Wformat  -w;
	echo "Iniciando o projeto :) \n\n"
	./app.exe 
test:
	#!/bin/sh
	echo "Removendo arquivos de testes antigos..."
	rm -rf ./tests/test.exe
	echo "Compilando testes ..."
	gcc -o ./tests/test.exe ./tests/string_replace.test.c ; 
	echo "Iniciando testes \n"
	./tests/test.exe