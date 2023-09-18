#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <vector>
#include "./pilha.h"

class Avaliacao {
    private:
        int _resultado;
        int _n;
        Pilha *_atributos;
        Pilha *_expressao;

    public:
        Avaliacao(int n, std::vector<int> atributos, std::vector<char> expressao);
        void percorre_expressao();
        int avalia_trecho(Item *comeco, Item *fim);
        //int avalia_expressao();
        int avalia_or(int arg1, int arg2);
        int avalia_and(int arg1, int arg2);
        //int avalia_not(int arg1);
        //int avalia_parenteses();

};

#endif 