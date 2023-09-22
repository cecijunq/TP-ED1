#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include "./tipo_item.h"
#include "./item_pilha.h"

class Pilha {
    private:

        unsigned int _tamanho;
        ItemPilha *inicio;
        ItemPilha *fim;
    public:
        Pilha();
        ItemPilha *get_inicio();
        ItemPilha *get_fim();
        int getTamanho();
        void empilha(Item *item);
        Item *desempilha();
};

#endif