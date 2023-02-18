#include <iostream>

int main(){
  //
  // Criando array 'int'
  //
  // definindo tamanho do array.
  int sz = 5;
  int vetor_1[sz];
  // Inserindo valores.
  vetor_1[4] = 60;
  vetor_1[3] = 45;
  vetor_1[2] = 30;
  vetor_1[1] = 15;
  vetor_1[0] = 5;
  
  // Criando outra 'var' e atrubuindo valor em uma linha.
  int vetor_2[8] = {9, 2, 3, 1, 1, 0, -4, 128};

  // Operação para "descobrir" o tamanho de vetor em qualquer SO, ao invés de dividir por 4. 
  int sz_v1 = ( sizeof(vetor_1) / sizeof(vetor_1[0]) );
  sz_v1 -= 1; // Para pegar o indice correto.

  for (int i = 0; i <= sz_v1; i++) {
    std::cout << vetor_1[i] << std::endl;
  }

  std::cout << "----------------" << std::endl;

  int sz_v2 = ( sizeof(vetor_2) / sizeof(vetor_2[0]) );
  sz_v2 -= 1;

  for (int i = 0; i <= sz_v2; i++) {
    std::cout << vetor_2[i] << std::endl;
  }

  return 0;
}
