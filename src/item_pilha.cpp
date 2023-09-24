#include "../include/item_pilha.h"

ItemPilha::ItemPilha(Item *item, ItemPilha *anterior) {
    _elemento = item;
    _anterior = anterior;
    _proximo = nullptr;
}

Item *ItemPilha::get_container_item() {
    return _elemento;
}

void ItemPilha::conecta_anterior(ItemPilha *anterior) {
    _anterior = anterior;
}

void ItemPilha::conecta_proximo(ItemPilha *proximo) {
    _proximo = proximo;
}

ItemPilha *ItemPilha::get_anterior() {
    return _anterior;
}