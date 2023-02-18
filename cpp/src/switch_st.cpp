#include <iostream>

int main(){

  int n;

  std::cout << "Entre com um numero inteiro positivo: ";
  std::cin >> n;

  switch(n){
      case 1:
      std::cout << "Numero primo: " << n << std::endl;
      break;
      case 2:
      std::cout << "Numero não primo: " << n << std::endl;
      break;
      case 3:
      std::cout << "Numero primo: " << n << std::endl;
      break;
      default:
      std::cout << "---- Fora da Lista ----" << std::endl;
      break;
  }

  return 0;
}
