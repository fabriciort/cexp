#include <cstdlib>
#include <iostream>

#define TAMVET(v) (sizeof(v) / sizeof(v[0]))  

// Jogo da forca v.0
// Versão não eficiente

int main(){
  char palavra[15], letra[1], compPalavra[15];
  int tamanhoPalavra, chanches, acertos;
  bool usrAcerto;

  tamanhoPalavra = TAMVET(palavra);
  chanches = 12;
  tamanhoPalavra = 0;
  acertos = 0;
  usrAcerto = false;

  jg:

  std::system("clear");
  std::cout << "\n+ JOGO DA FORCA +\n" << std::endl;

  std::cout << "Digite a palava secreta: ";
  std::cin >> palavra;

  std::system("clear");
  std::cout << "Tela limpa!\n\n+ JOGO DA FORCA +\n\n";

  int i = 0;
  /*
   * Conteúdo importante. a "flag" '\0' (contra-barra zero), indica a 
   * tecla 'Enter', que indica o fim de uma "string"  ou dado.
   */
  while(palavra[i] != '\0'){
    i++; // Enquanto 'palavra' ainda não tiver encontrado o "fim", é incrementado o tamanho do array.
    tamanhoPalavra++;
  }

  for(i = 0; i < 15; i++){
    compPalavra[i] = '-';
  }

  // Laço de repetição do jogo.
  while (chanches > 0 and (acertos < tamanhoPalavra)) {
    std::system("clear");
    std::cout << "\n+ JOGO DA FORCA +\n\n";
    std::cout << chanches << " chanches restantes. \n" << std::endl;
    std::cout << "| Palavra secreta \n|> ";
    for (i = 0; i < tamanhoPalavra; i++) {
      std::cout << compPalavra[i];
    }

    std::cout << "\n\nDigite uma letra: ";
    std::cin >> letra[0];

    for (i = 0; i < tamanhoPalavra; i++) {
      if (palavra[i] == letra[0]) {
        usrAcerto = true;
        compPalavra[i] = palavra[i];
        acertos++;
      }
    }
    //Operador not '!'
    if (!usrAcerto) {
      chanches--;
    }
    usrAcerto = false;
  }
  if (acertos == tamanhoPalavra){
    std::system("clear");
    std::cout << "\n    | FIM DO JOGO |\n\nVocê encontrou a palavra escondida!\n\n| A palavra era\n|> ";
    for (i = 0; i < tamanhoPalavra; i++) {
      std::cout << compPalavra[i];
    }
    std::cout << "\nPARABÉNS!\n\n";
  }else{
    std::cout << "\nVocê NÃO Encontrou a palavra \n :(\nQuem sabe na próxima!\n";
  }
  char opt;
  std::cout << "Deseja jogar novamente? [s/N] ? |> ";
  std::cin >> opt;
  if (opt == 's' or opt == 'S') {
    std::system("clear");
    goto jg;
  }
  std::system("clear");
  std::cout << "\nTchau ! :D\n" << std::endl;

  return 0;
}
