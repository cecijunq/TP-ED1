#include "../include/tipo_item.h"

Item::Item(char elemento, Item *anterior) {
    _elemento = elemento;
    _anterior = anterior;
    _proximo = nullptr;
}
/*
Item::Item() {
    _elemento = '3';
    _anterior = nullptr;
    _proximo = nullptr;
}
*/

Item::~Item() {}

char Item::get_elemento() {
    return _elemento;
}

void Item::set_elemento(char novo_elemento) {
    _elemento = novo_elemento;
}

void Item::set_novo_prox(Item *novo_elemento) {
    _proximo = novo_elemento;
}

void Item::set_novo_ant(Item *novo_elemento) {
    _anterior = novo_elemento;
}

Item *Item::get_prox() {
    return _proximo;
}

Item *Item::get_ant() {
    return _anterior;
}

void Item::linka_elementos(Item *anterior) {
    _anterior = anterior;
    _proximo = nullptr;
}