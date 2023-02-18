#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>

/*
 
    Operador Ternário
 Para utilização em teste com
 retorno simples, para otimização
 do programa.
 
 */

int main(){

/* Sintaxe do operador:
 
      (expressão lógica) ? true_VALOR : false_VALOR
           operação     /\      ^            ^
                     operador   |            |
                            verdadeiro     falso
*/
    
  float curr_bal = 500;
    
  std::map<int, float> prod;
    
  prod = {
        { 1, 10.59 },
        { 2, 99.99 },
        { 3, 45.99 }
  };
    
  std::cout << "Produtos:" << std::endl;
    
  for (auto const & [k, v] : prod){
    std::cout << k << "º prod. >" << " Preço: " << v << std::endl;
  }
    
  int esc_prod;
  compra: // <- label
  std::printf("Seu dinheiro: %.2f", curr_bal);
  // std::cout << "Seu dinheiro: " << curr_bal <<std::endl;
  std::cout << std::endl << "Escolha o produto: ";
  std::cin >> esc_prod;
    
  (esc_prod == 3) ? curr_bal -= 45.99 : curr_bal;
  (esc_prod == 2) ? curr_bal -= 99.99 : curr_bal;
  (esc_prod == 1) ? curr_bal -= 10.59 : curr_bal;
    
  while (curr_bal > 0 and curr_bal > 10.59) {
    goto compra;
  }if (curr_bal <= 10.59){
    // std::cout << "Voce nao tem dinheiro suficiente para comprar nenhum item da lista, sobraram: " << curr_bal << std::endl;
    std::printf("Voce nao tem dinheiro suficiente para comprar nenhum item da lista, sobraram: %.2f\n", curr_bal);
    if (curr_bal < 0) {
      std::printf("Voce esta em debito, devendo %.2f, portando seu saldo esta negativo.\n", curr_bal); 
    }
  }

  std::cout << "Acabou a grana." << std::endl;
    
  return 0;
}
