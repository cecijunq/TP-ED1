#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <vector>
#include "./pilha.h"
#include "./lista.h"

class Avaliacao {
    private:
        //int _resultado;
        //int _n;
        /*
        Pilha *_atributos;
        Pilha *_expressao;
        */
        //Lista *_atributos;
        Lista *_expressao;

    public:
        Avaliacao(std::string expressao, std::string atributos);
        char percorre_expressao();
        void avalia_trecho(Item *comeco, Item *fim);
        //int avalia_expressao();
        char avalia_or(char arg1, char arg2);
        char avalia_and(char arg1, char arg2);
        char avalia_not(char arg1);
        //int avalia_parenteses();

};

#endif 