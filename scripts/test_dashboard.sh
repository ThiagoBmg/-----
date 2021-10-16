#!/bin/sh
echo "Removendo versões anteriores"
rm -rf dash_test ;
echo "Compilando o projeto..."
gcc -o ./tests/dash_test ./services/dashboard.c;
echo "Iniciando o projeto :) \n\n"
./tests/dash_test
