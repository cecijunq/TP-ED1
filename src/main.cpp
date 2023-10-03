#include <iostream>
#include <string>

#include "../include/avaliacao.h"
#include "../include/satisfabilidade.h"

class arg_invalidos {};

int main(int argc, char **argv) {
    if(argc != 4) {
        std::cout << "Quantidade inválida de parâmetros." << std::endl;
        //throw arg_invalidos();
    }
    
    if(argv[1] == std::string("-a")) {
        Avaliacao a = Avaliacao(argv[2], argv[3]);
        std::cout << a.avalia_trecho() << std::endl;
    } else if(argv[1] == std::string("-s")) {
        Satisfabilidade s = Satisfabilidade(argv[2], argv[3]);
        std::cout << s.resolve_problema(s.get_raiz()) << std::endl;
    }

}