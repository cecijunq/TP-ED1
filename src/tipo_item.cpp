#include "../include/tipo_item.h"

Item::Item(int elemento, Item *anterior) {
    _elemento = elemento;
    _anterior = anterior;
    _proximo = nullptr;
}

Item::~Item() {}

int Item::get_elemento() {
    return _elemento;
}

void Item::set_elemento(char novo_elemento) {
    _elemento = novo_elemento;
}

void Item::set_novo_prox(Item *novo_elemento) {
    _proximo = novo_elemento;
}

Item *Item::get_prox() {
    return _proximo;
}

Item *Item::get_ant() {
    return _anterior;
}

void Item::linka_elementos(Item *novo) {

}