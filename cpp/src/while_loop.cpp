#include <iostream>

int main(){
  /*
   *  While Loop, contador simples.
   */

  int n, max, ent;
  n = 0;
  max = 100000;
  ent = 0;


  while (n <= max) {
    
    std::cout << "Entre com um numero para somar a n.\nAtual valor de n: " << n << "\nEntre com um valor > ";
    std::cin >> ent;
    
    n += ent;

  }

  std::cout << "Limite máximo alcançado: " << max << std::endl;

  return 0;
}
