#!/bin/sh
echo "Removendo versões anteriores"
rm -rf app ;
echo "Compilando o projeto..."
gcc -o app main.c;
echo "Iniciando o projeto :) \n\n"
./app 
