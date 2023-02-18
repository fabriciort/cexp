#include <iostream>

int main(){

  int contador;
  contador = 0;

  while (contador < 100) {
    std::cout << contador << std::endl;
    contador++;

    if (contador == 23) {
      break;
    }

  }
  
  return 0;
}
