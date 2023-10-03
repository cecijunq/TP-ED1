#ifndef AVALIACAO_H
#define AVALIACAO_H

#include "./lista.h"
#include <vector>
#include <map>

class Avaliacao {
    private:
        int _tamanho;
        Lista stack;
        Lista operadores;

    public:
        Avaliacao(std::string expressao, std::string atributos);
        Avaliacao();
        int precedence(char operador);
        void postfixEval(std::string expressao, std::string atributos);
        Lista get_stack();
        char avalia_trecho();
        char avalia_or(char arg1, char arg2);
        char avalia_and(char arg1, char arg2);
        char avalia_not(char arg1);

};

#endif 