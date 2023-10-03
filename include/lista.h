#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include "./tipo_item.h"

class Lista {
    private:
        unsigned int _tamanho;
        Item *inicio;
        Item *fim;
    public:
        Lista();
        //Lista(std::string expressao, std::string atributos);
        Item *get_inicio();
        Item *get_fim();
        int getTamanho();
        void muda_fim(Item *novo_elemento);
        void muda_inicio(Item *novo_elemento);
        void set_nesimo_item(int pos, char n);
};

#endif