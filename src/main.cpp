#include <iostream>
#include <string>
#include <getopt.h>

#include "../include/avaliacao.h"
#include "../include/satisfabilidade.h"

class arg_invalidos {};
class qntd_invalida_arg {};

// definicoes de operacoes a serem testadas
#define AVALIACAO 1
#define SATISFABILIDADE 2

// variaveis globais para opcoes
static int opescolhida;

void parse_args(int argc,char ** argv) {
    if(argc != 4) {
        throw qntd_invalida_arg();
    }
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

        default:
            throw arg_invalidos();
       }
     }
}

int main(int argc, char **argv) {
    try {
        parse_args(argc,argv);

    } catch(qntd_invalida_arg &e) {
        
        return 1;

    } catch(arg_invalidos &e) {
        return 1;
    }

    switch(opescolhida) {
        case AVALIACAO:
        {
            Avaliacao av;
            try {
                av = Avaliacao(argv[2], argv[3]);

            } catch(parametros_invalidos &e) {
                return 1;
            } catch(elemento_invalido &e) {
                return 1;
            }
            std::cout << av.avalia_trecho() << std::endl;
            break;
        }
        case SATISFABILIDADE:
        {
            Satisfabilidade st = Satisfabilidade(argv[2], argv[3]);
            st.avalia_satisfabilidade();
            break;
        }
    }
}