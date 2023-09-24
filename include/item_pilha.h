#ifndef ITEM_PILHA_H
#define ITEM_PILHA_H

#include "./tipo_item.h"

class ItemPilha {
    private:
        Item *_elemento;
        ItemPilha *_anterior;
        ItemPilha *_proximo;

    public:
        ItemPilha(Item *item, ItemPilha *anterior);
        Item *get_container_item();
        void conecta_anterior(ItemPilha *anterior);
        void conecta_proximo(ItemPilha *proximo);
        ItemPilha *get_anterior();

};

#endif