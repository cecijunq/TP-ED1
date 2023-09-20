#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <vector>
#include "./pilha.h"
#include "./lista.h"

class Avaliacao {
    private:
        int _resultado;
        int _n;
        /*
        Pilha *_atributos;
        Pilha *_expressao;
        */
        Lista *_atributos;
        Lista *_expressao;

    public:
        Avaliacao(int n, std::vector<int> atributos, std::vector<char> expressao);
        void percorre_expressao();
        char avalia_trecho(Item *comeco, Item *fim);
        //int avalia_expressao();
        char avalia_or(char arg1, char arg2);
        char avalia_and(char arg1, char arg2);
        char avalia_not(char arg1);
        //int avalia_parenteses();

};

#endif 