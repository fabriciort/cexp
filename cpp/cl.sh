#!/bin/bash
clear
echo
printf "\033[1;34m Compilando..."
echo
# Cria o diretório 'bin/linux' se ele não existir
mkdir -p bin/linux

# Extrai o nome do arquivo sem a extensão 'cpp'
filename=$(basename "$1" .cpp)

# Compila o arquivo C++ especificado usando Clang
clang++ -std=c++11 -std=c++17 -o bin/linux/"$filename" "$1"
clear
echo
printf "\033[1;33m Abrindo...\033[0m"
echo
echo
./bin/linux/"$filename"
