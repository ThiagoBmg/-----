#!/bin/sh
echo "Removendo arquivos de testes antigos..."
rm -rf ./tests/test.exe
echo "Compilando testes ..."
gcc -o ./tests/test.exe ./tests/string_replace.test.c ; 
echo "Iniciando testes \n"
./tests/test.exe

