#include <iostream>
#include <string>
#include <regex>

#include "../include/avaliacao.h"
#include "../include/satisfabilidade.h"


int main(int argc, char **argv) {
    if(argc != 3) {
        std::cout << "Quantidade inválida de parâmetros." << std::endl;
        return 1;
    }

        Avaliacao a = Avaliacao(argv[1], argv[2]);
        std::cout << "RESULTADO AQUI: " << a.avalia_trecho() << std::endl;
    /*if(argv[1] == "-a") {
    
    } else if(argv[1] == "-s")
        Satisfabilidade s = Satisfabilidade(argv[2], argv[3]);
        */

}