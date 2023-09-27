#include "../include/pilha.h"

Pilha::Pilha() {
    _tamanho = 0;
    inicio = nullptr;
    fim = nullptr;
}

//Item *Pilha::get_next_element() {}

Item *Pilha::get_inicio() {
    return inicio;
}

Item *Pilha::get_fim() {
    return fim;
}

int Pilha::getTamanho() {
    return _tamanho;
}

void Pilha::empilha(Item *item) {
    //Item *item_p = new Item(item, fim);

    /*if(_tamanho == 0) {
        inicio = item_p;
    } else {
        if(item->get_elemento() == '~' && (fim->get_container_item()->get_elemento() == '&' || fim->get_container_item()->get_elemento() == '|')) {

        } else if(item->get_elemento() == '&' && fim->get_container_item()->get_elemento() == '|') {

        } else {
            fim->conecta_proximo(item_p);
        }
    } */
    if(_tamanho == 0) {
        inicio = item;
    } else {
        fim->conecta_proximo(item);
    }
    //else {//item_p->conecta_anterior(fim);}
    fim = item;
    _tamanho++;
}
/*
void Pilha::empilha(char item) {
    Item *novo = new Item(item, fim);

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
    Item *aux = fim->get_ant();
    //Item *aux2 = fim;
    Item *desempilhado = fim;
    //delete aux2;
    fim = aux;

    return desempilhado;
}
