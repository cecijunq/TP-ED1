#include "../include/lista.h"
#include "../include/pilha.h"
#include <string>

Lista::Lista() {
    _tamanho = 0;
    inicio = nullptr;
    fim = nullptr;
}

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
