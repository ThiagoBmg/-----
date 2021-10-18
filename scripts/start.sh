#!/bin/sh
echo "Removendo versões anteriores"
rm -rf app.exe ;
echo "Compilando o projeto..."
gcc -o app.exe main.c;
echo "Iniciando o projeto :) \n\n"
./app.exe 
