#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include "./tipo_item.h"

class Pilha {
    private:
        //int _posicoes[100];
        unsigned int _tamanho;
        Item *inicio;
        Item *fim;
    public:
        Pilha();
        //Item *get_next_element();
        Item *get_inicio();
        Item *get_fim();
        int getTamanho();
        //void empilha(char item);
        void empilha(Item *item);
        Item *desempilha();
};

#endif