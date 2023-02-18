#include <iostream>
#include <cstdlib>

#define TAMVET(v) (sizeof(v) / sizeof(v[0])) // Utilizando o mesmo 
// conceito do arquivo de array, e criando uma "macro", para facilitar
// o acesso a informação de tamanho de um "array"/"vetor".

int main ()
{
  /* L: Linha | C: Coluna
   *                         L  C
   *      int matriz_exemplo[3][3];
   *
   *        0   1   2
   *      -------------
   *    0 | a | b | c |
   *    1 | d | e | f |
   *    2 | g | h | i |
   *      -------------
   *
   * */

  int matriz[2][5]; // Matrix de 2 linhas 'i' e 5 colunas 'j'

  // Adicionando valores manualmente em algumas posições da matriz.
  matriz[0][2] = 32;
  matriz[0][4] = 64;
  matriz[1][1] = 16;
  matriz[1][0] = 8;
  // Preenchendo o restante de espaços com '0's.
  matriz[0][0] = 0;
  matriz[0][1] = 0;
  matriz[0][3] = 0;
  matriz[1][2] = 0;
  matriz[1][3] = 0;
  matriz[1][4] = 0;
  
  /*  A matriz tem a seguinte ordem.
   *  
   *        0    1    2    3    4
   *     --------------------------
   *   0 |  0  | 0  | 32 | 0  | 64 |
   *   1 |  8  | 16 | 0  | 0  | 0  |
   *     --------------------------
   * */
  // Obtendo o tamanho de cada dimensão da matriz.
  inicio:
  int tamLin = TAMVET(matriz);
  int tamCol = TAMVET(matriz[0]);

  int l, c; // variaveis de controle.
  
  std::cout << "Matriz " << tamLin << "x" << tamCol << ":" << std::endl;

  for (l = 0;l  < tamLin; l++) { // <- Este 'for' perco. as linhas.
    for (c = 0; c < tamCol; c++) { // <- Este 'for' perco as colunas.
      std::cout << matriz[l][c] << "  ";
    }
    std::cout << std::endl;
  }

  int matriz_forFill[6][8];
  
  tamLin = TAMVET(matriz_forFill);
  tamCol = TAMVET(matriz_forFill[0]);

  std::cout << "Matriz " << tamLin << "x" << tamCol << " (com zeros):" << std::endl;

  // Preenche matriz vazia com '0'
  for (l = 0; l < tamLin; l++) {
    for (c = 0; c < tamCol; c++) {
      matriz_forFill[l][c] = 0;
      std::cout << matriz_forFill[l][c] << "  ";
    }
    std::cout << std::endl;
  }

  int matriz_usr[3][3];

  tamLin = TAMVET(matriz_usr);
  tamCol = TAMVET(matriz_usr[0]);

  std::cout << "Deseja preencher a matriz " << tamLin << "x" << tamCol << "? [s/N]: ";
  char opt;
  std::cin >> opt;
  if (opt == 's' or opt == 'S') {
    goto matriz;
  }else{
    goto fim;
  }

  matriz:

  std::cout << "\nPreencha esta matriz " <<  tamLin << "x" << tamCol << ":" << std::endl;
  
    // Preenche matriz vazia com entrada do usuario.
  for (l = 0; l < tamLin; l++) {
    for (c = 0; c < tamCol; c++) {
      std::cout << "Entre com um valor inteiro: ";
      std::cin >> matriz_usr[l][c];
    }
    std::cout << std::endl;
  }
  
  std::system("clear");
  std::cout << "Matriz " << tamLin << "x" << tamCol << " preenchida pelo usuario:" << std::endl;

  for (l = 0;l  < tamLin; l++) {
    for (c = 0; c < tamCol; c++) {
      std::cout << matriz_usr[l][c] << "  ";
    }
    std::cout << std::endl;
  }

  std::cout << "Finalizar programa? [s/N]: ";
  std::cin >> opt;
  if (opt == 's' or opt == 'S'){
    goto fim;
  }else {
    std::system("clear");
    std::cout << "\nRetornando...\n\n";
    goto inicio;
  }

  fim:

  std::system("clear");
  std::cout << "\nFim do programa, tela limpa." << std::endl;

  return 0;
}
