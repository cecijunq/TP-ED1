#include "../include/lista.h"
#include <string>

Lista::Lista() {
    _tamanho = 0;
    inicio = nullptr;
    fim = nullptr;
}

Lista::~Lista() {}

Item *Lista::get_inicio() {
    return inicio;
}

Item *Lista::get_fim() {
    return fim;
}

int Lista::getTamanho() {
    return _tamanho;
}

void Lista::muda_fim(Item *novo_elemento) {
    fim = novo_elemento;
}

void Lista::muda_inicio(Item *novo_elemento) {
    inicio = novo_elemento;
}

void Lista::set_nesimo_item(int pos, char n) {
    Item *aux = inicio;
    for(int i = 0; i <= pos; i++) {
        aux->get_prox();
    }
    aux->set_elemento(n);
}