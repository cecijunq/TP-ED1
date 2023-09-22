#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include "./tipo_item.h"

class Lista {
    private:
        //int _posicoes[100];
        unsigned int _tamanho;
        Item *inicio;
        Item *fim;
    public:
        Lista(std::string expressao, std::string atributos);
        //Item *get_next_element();
        Item *get_inicio();
        Item *get_fim();
        int getTamanho();
        void adiciona_inicio(Item *novo_elemento);
        void muda_fim(Item *novo_elemento);
        void muda_inicio(Item *novo_elemento);
        //void empilha(char item);
        //void adiciona_elemento(Item *item);
        //Item *desempilha();
};

#endif