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
            /*std::string at = argv[3];
            int n_quantificadores = 0;
            for(int i = 0; i < at.size(); i++) {
                if(argv[3][i] == 'a' || argv[3][i] == 'e') {
                    n_quantificadores++;
                    if(n_quantificadores > 5) return 1;
                }
            }*/
            /*std::string at = argv[3];
            int n_quantificadores = 0;
            for(unsigned int i = 0; i < at.size(); i++) {
                if(argv[3][i] == 'a' || argv[3][i] == 'e') {
                    n_quantificadores++;
                    if(n_quantificadores > 5) return 1;
                }
            }
            Satisfabilidade st = Satisfabilidade(argv[2], argv[3]);
            st.avalia_satisfabilidade();
            break;*/
            try {
                Satisfabilidade st = Satisfabilidade(argv[2], argv[3]);
                st.avalia_satisfabilidade();

            } catch(qntd_invalida_quantif &e) {
                return 1;
            } catch(elemento_invalido &e) {
                return 1;
            }
            break;
        }
    }
}