all: 
	make start

start: 
	#!/bin/sh
	echo "Removendo versões anteriores"
	rm -rf app.exe;
	echo "Compilando o projeto..."	
	gcc -o app.exe main.c -w;
	echo "Iniciando o projeto :) \n\n"
	./app.exe 

test:
	#!/bin/sh
	echo "Removendo arquivos de testes antigos..."
	rm -rf ./tests/test.exe;
	echo "Compilando testes ..."
	gcc -o ./tests/test.exe ./tests/string_replace.test.c ; 
	echo "Iniciando testes \n"
	./tests/test.exe
build: 
	#!/bin/sh
#	docker rmi $(docker images -q);
#	docker stop $(docker ps -a -q);
#	docker rm $(docker ps -a -q);
	docker build -t app_image .;
	docker run -d -t app_image;
# --- tests only ---
#dashboard: 
#	#!/bin/sh
#	echo "Removendo arquivo do serviço de dashboard..."
#	rm -rf ./services/dash.exe;
#	echo "Compilando serviço ..."
#	gcc -o ./services/dash.exe ./services/dashboard.c -w; 
#	echo "Iniciando serviço \n"
#	./services/dash.exe