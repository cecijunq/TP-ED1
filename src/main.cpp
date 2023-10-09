#include <iostream>
#include <string>
#include <getopt.h>

#include "../include/avaliacao.h"
#include "../include/satisfabilidade.h"

class arg_invalidos {};

// definicoes de operacoes a serem testadas
#define AVALIACAO 1
#define SATISFABILIDADE 2

// variaveis globais para opcoes
static int opescolhida;

void parse_args(int argc,char ** argv) {
    // variavel auxiliar
    int c;

    while ((c = getopt(argc, argv, "as")) != EOF){
       switch(c) {
         case 's':
	        opescolhida = SATISFABILIDADE;
            break;
         case 'a':
	        opescolhida = AVALIACAO;
            break;
       }
     }
}

int main(int argc, char **argv) {
    if(argc != 4) {
        std::cout << "Quantidade inválida de parâmetros." << std::endl;
        //throw arg_invalidos();
    }

    parse_args(argc,argv);

    switch(opescolhida) {
        case AVALIACAO:
        {
            Avaliacao av = Avaliacao(argv[2], argv[3]);
            std::cout << av.avalia_trecho() << std::endl;
            break;
        }
        case SATISFABILIDADE:
        {
            Satisfabilidade st = Satisfabilidade(argv[2], argv[3]);
            std::cout << st.resolve_problema(st.get_raiz()) << std::endl;
            break;
        }
    }
    
    /*
    if(argv[1] == std::string("-a")) {
        Avaliacao a = Avaliacao(argv[2], argv[3]);
        std::cout << a.avalia_trecho() << std::endl;
    } else if(argv[1] == std::string("-s")) {
        Satisfabilidade s = Satisfabilidade(argv[2], argv[3]);
        std::cout << s.resolve_problema(s.get_raiz()) << std::endl;
    }
    */
}