#include <iostream>

using namespace std;

int main(){
  int nM = 32;
  for (int n = 0; n < nM; n++) {
    if (n % 2 == 0 and n != 0) {
      cout << "O numero " << n << " é par." << endl;
    }
  }

  return 0;
}
