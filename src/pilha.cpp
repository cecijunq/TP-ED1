#include "../include/pilha.h"

Pilha::Pilha() {
    _tamanho = 0;
    inicio = nullptr;
    fim = nullptr;
}

Item *Pilha::get_next_element() {

}

Item *Pilha::get_inicio() {
    return inicio;
}

Item *Pilha::get_fim() {
    return fim;
}

int Pilha::getTamanho() {
    return _tamanho;
}

void Pilha::empilha(int item) {
    Item *novo = new Item(item, fim);

    if(_tamanho == 0) 
        inicio = novo;
    fim = novo;
    _tamanho++;
}

Item *Pilha::desempilha() {
    if(getTamanho() == 0) {
        std::cout << "Lista está vazia" << std::endl;
        return 0;
    }

    _tamanho--;
    Item *aux = fim->get_ant();
    Item *desempilhado = fim;
    delete fim;
    fim = aux;

    return desempilhado;
}
