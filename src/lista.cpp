#include "../include/lista.h"
#include <string>

Lista::Lista(std::string expressao, std::string atributos) {
    _tamanho = 0;
    Item *novo;

    for(unsigned int i = 0; i < expressao.size(); i++) {
        if(expressao[i] != ' ') {
            //std::cout << expressao[i] << std::endl;
            if(_tamanho == 0) {
                novo = new Item(expressao[i], nullptr);
                inicio = novo;
                fim = novo;
            } else if(expressao[i] == '~' || expressao[i] == '&' || expressao[i] == '|' || expressao[i] == '(' || expressao[i] == ')'){
                novo = new Item(expressao[i], fim);
                fim->set_novo_prox(novo);
                fim = novo;
            } else {
                novo = new Item(atributos[expressao[i] - '0'], fim);
                fim->set_novo_prox(novo);
                fim = novo;
            }
            _tamanho++;
        }
    }

    /*
    std::cout << "endereço fim = " << fim << std::endl;
    std::cout << "endereço inicio = " << inicio << std::endl;
    for(Item *c = inicio; c != nullptr; c = c->get_prox()) {
        std::cout << c << std::endl;
        std::cout << c->get_elemento() << std::endl;
        std::cout << c->get_ant() << std::endl;
        std::cout << c->get_prox() << std::endl;
        std::cout << std::endl;
    }*/
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

void Lista::adiciona_inicio(Item *novo_elemento) {
    inicio = novo_elemento;
}

void Lista::muda_fim(Item *novo_elemento) {
    fim = novo_elemento;
}

void Lista::muda_inicio(Item *novo_elemento) {
    inicio = novo_elemento;
}
