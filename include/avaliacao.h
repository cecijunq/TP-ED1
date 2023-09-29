#ifndef AVALIACAO_H
#define AVALIACAO_H

//#include "./pilha.h"
#include "./lista.h"

class Avaliacao {
    private:
        int _tamanho;
        Lista *stack;
        Lista *operadores;

    public:
        Avaliacao(std::string expressao, std::string atributos);
        void postfixEval(std::string expressao, std::string atributos);
        int precedence(char operador);
        char avalia_trecho();
        char avalia_or(char arg1, char arg2);
        char avalia_and(char arg1, char arg2);
        char avalia_not(char arg1);

};

#endif 