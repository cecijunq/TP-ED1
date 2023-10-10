#include "../include/item_arvore.h"

ItemArvore::ItemArvore(std::string atributos) {
    _atributos = atributos;
    esq = nullptr;
    dir = nullptr;
}

int ItemArvore::muda_valor_quantificador() {
    for(unsigned int i = 0; i < _atributos.size(); i++) {
        if(_atributos[i] == 'a' || _atributos[i] == 'e') {
            quantificador = _atributos[i];

            _atributos[i] = '0';
            ItemArvore *ramo_esq = new ItemArvore(_atributos);
            
            _atributos[i] = '1';
            ItemArvore *ramo_dir = new ItemArvore(_atributos);

            _atributos[i] = quantificador;
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

char ItemArvore::get_quantificador() {
    return quantificador;
}

std::string ItemArvore::get_atributos() {
    return _atributos;
}

void ItemArvore::set_atributos(std::string novo_atributos) {
    _atributos = novo_atributos;
}