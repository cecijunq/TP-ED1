#include "../include/pilha.h"

Pilha::Pilha() {
    _tamanho = 0;
    inicio = nullptr;
    fim = nullptr;
}

//Item *Pilha::get_next_element() {}

ItemPilha *Pilha::get_inicio() {
    return inicio;
}

ItemPilha *Pilha::get_fim() {
    return fim;
}

int Pilha::getTamanho() {
    return _tamanho;
}

void Pilha::empilha(Item *item) {
    ItemPilha *item_p = new ItemPilha(item, fim);

    if(_tamanho == 0) {
        inicio = item_p;
    } else {
        fim->conecta_proximo(item_p);
    }
    //else {//item_p->conecta_anterior(fim);}
    fim = item_p;
    _tamanho++;
}
/*
void Pilha::empilha(char item) {
    ItemPilha *novo = new Item(item, fim);

    if(_tamanho == 0) 
        inicio = novo;
    fim = novo;
    _tamanho++;
}
*/

Item *Pilha::desempilha() {
    if(getTamanho() == 0) {
        std::cout << "Lista está vazia" << std::endl;
        return 0;
    }

    _tamanho--;
    ItemPilha *aux = fim->get_anterior();
    //ItemPilha *aux2 = fim;
    ItemPilha *desempilhado = fim;
    //delete aux2;
    fim = aux;

    return desempilhado->get_container_item();
}
