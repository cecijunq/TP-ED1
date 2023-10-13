#include "../include/item_arvore.h"

ItemArvore::ItemArvore(std::string atributos) {
    _atributos = atributos;
    esq = nullptr;
    dir = nullptr;
}

int ItemArvore::muda_valor_quantificador() {
    std::string para_esq = _atributos;
    std::string para_dir = _atributos;
    for(unsigned int i = 0; i < _atributos.size(); i++) {
        if(_atributos[i] == 'a' || _atributos[i] == 'e') {
            pos_quantificador = i;
            quantificador = _atributos[i];

            para_esq[i] = '0';
            ItemArvore *ramo_esq = new ItemArvore(para_esq);
            
            para_dir[i] = '1';
            ItemArvore *ramo_dir = new ItemArvore(para_dir);

            esq = ramo_esq;
            dir = ramo_dir;

            return 1;
        }
    }
    return 0;
}

ItemArvore *ItemArvore::get_esq() {
    return esq;
}

ItemArvore *ItemArvore::get_dir() {
    return dir;
}

char ItemArvore::get_resultado() {
    return resultado;
}

void ItemArvore::set_resultado(char valor) {
    resultado = valor;
}

char ItemArvore::get_quantificador() {
    return quantificador;
}

std::string ItemArvore::get_atributos() {
    return _atributos;
}

void ItemArvore::set_atributos(std::string novo_atributos) {
    _atributos = novo_atributos;
}

int ItemArvore::get_pos_quantificador() {
    return pos_quantificador;
}