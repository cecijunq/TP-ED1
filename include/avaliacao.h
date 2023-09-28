#ifndef AVALIACAO_H
#define AVALIACAO_H

//#include <vector>
//#include "./pilha.h"
#include "./lista.h"

class Avaliacao {
    private:
        //Lista *_expressao;
        Lista *stack;
        Lista *operadores;
       // Lista *stack;
       // Lista *operadores;

    public:
        Avaliacao(std::string expressao, std::string atributos);
        void postfixEval(std::string expressao, std::string atributos);
        //char percorre_expressao();
        int precedence(char operador);
        char avalia_trecho();
        //void avalia_trecho(Item *comeco, Item *fim);
        //int avalia_expressao();
        char avalia_or(char arg1, char arg2);
        char avalia_and(char arg1, char arg2);
        char avalia_not(char arg1);
        //int avalia_parenteses();

};

#endif 