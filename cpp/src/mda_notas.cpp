#include <iostream>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    // -- FIRST BLOCK - BEGIN
    
//    std::cout << "____________________________" << std::endl;
//    std::cout << "INVERT NUMBER VALUE:\n";
//    int num_1;
//
//    num_1 = 9;
//
//    std::cout << "Positive > " << num_1 << std::endl;
//
////    Classic Math Method <- This update the value of the var
//    num_1 = num_1 * -1;
//    std::cout << "Negative > " << num_1 << std::endl;
//
////    C++ Method <- This update the value in runtime and not "permanently".
//    std::cout << -num_1 << std::endl; // The value is positive, the minus signal invert the negative number to a positive.
////    invert the var value to positive
//    num_1 = -num_1;
//    std::cout << num_1 << std::endl;
//    std::cout << "____________________________" << std::endl;
    
    // -- FIRST BLOCK - END
    
    // SECOND BLOCK - BEGIN
    
    mda:
    
    std::cout << "\n____________________________" << std::endl;
    std::cout << "CONDICIONAL - IF, ELSE, Goto - Média Final.\n" << std::endl;
    
    float nt[3], ntUser[3], clc;
    std::string consolidação;
    bool err = false;
    
    for (int i = 0; i <= 2; i++) {
        
        std::cout << "| Digite a " << i + 1 << "ª nota: ";
        std::cin >> ntUser[i];

        if (ntUser[i] < 0 || ntUser[i] > 10){
            err = true;
            break;

        }else{
            nt[i] = ntUser[i];
        }
    }

    clc = (nt[0] + nt[1] + nt[2]) / 3;

/*
    Media > que 6 => Aprovado
    Media < que 4 => Reprovado
    Media < que 6 e >= 4 => Recuperação
*/
    
    if (clc >= 6) {
        consolidação = "Aprovado";
    }else if (clc < 6 && clc >= 4){
        consolidação = "Recuperação";
    }else if (clc > 0 && clc < 4){
        consolidação = "Reprovado";
    }
    if(err == true){
        std::printf("\nNota final: --\n");
        std::cout << "[!] ERRO. O Usuario digitou nota inválida.";
    }else{
        std::printf("\nNota final: %.1f", clc);
        std::cout << "\nConsolidação: " << consolidação << std::endl;
    }
    
    char opt;
    
    std::cout << "\nInserir outras notas? [s/N]: ";
    std::cin >> opt;

    if (opt == 's' or opt == 'S'){
        clc = 0;
        goto mda;
    }else{
        std::cout << "\nFINAL.\n____________________________" << std::endl;
    }
    
    // SECOND BLOCK - END
    
    return 0;
}
