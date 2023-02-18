#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int contador = 20;

  while (contador < 3) {
    cout << "Contador: " << contador << endl;
    contador++;
  }

  do {
    cout << "Contador: " << contador << endl;
    contador++;
  }while (contador < 3);

  cout << "Loop finalizado" << endl;

  return 0;
}
