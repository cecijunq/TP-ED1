#ifndef TIPO_ITEM_H
#define TIPO_ITEM_H

#include <iostream>

class Item {
    private:
        char _elemento;
        Item *_proximo;
        Item *_anterior;
    public:
        Item(char elemento, Item *anterior);
        Item();
        ~Item();
        char get_elemento();
        void set_elemento(char novo_elemento);
        void set_novo_prox(Item *novo_elemento);
        void set_novo_ant(Item *novo_elemento);
        Item *get_prox();
        Item *get_ant();
        void linka_elementos(Item *novo);
        void conecta_proximo(Item *proximo);
};

#endif