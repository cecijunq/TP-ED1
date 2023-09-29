#include "../include/satisfabilidade.h"

Satisfabilidade::Satisfabilidade(std::string expressao, std::string atributos) {
    a = new Avaliacao(expressao, atributos);

}