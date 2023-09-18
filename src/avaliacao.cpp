#include "../include/avaliacao.h"
#include <regex>
#include <vector>

//teste
class ParametrosInvalidos {};

Avaliacao::Avaliacao(int n, std::vector<int> atributos, std::vector<char> expressao) {
    if(atributos.size() > 10e6 || expressao.size() > 100) {
        throw ParametrosInvalidos();
    }

    //_atributos = atributos;
    //_expressao = _expressao;
    _n = atributos.size();
}

void Avaliacao::percorre_expressao() {
    Pilha parenteses_pos = Pilha();
    Pilha not_pos = Pilha();
    Pilha and_pos = Pilha();
    Pilha or_pos = Pilha();

    for(Item *aux = _expressao->get_inicio(); aux != nullptr; aux = aux->get_prox()) {
        if(aux->get_elemento() == '(') {
            parenteses_pos.empilha(aux->get_elemento());

        } else if(aux->get_elemento() == ')') {
            Item *comeco = parenteses_pos.desempilha();
            avalia_trecho(comeco, aux);

        }
    }
}

int Avaliacao::avalia_trecho(Item *comeco, Item *fim) {
    for(Item *i = comeco; i < fim; i = i->get_prox()) {
        if(i->get_elemento() == '~') {
            int arg1 = i->get_prox()->get_elemento();
            i->set_elemento(!arg1);
            i->set_novo_prox(i->get_prox()->get_prox());
        }
    }

    for(Item *i = comeco; i < fim; i = i->get_prox()) {
        if(i->get_elemento() == '&') {
            int arg1 = i->get_ant()->get_elemento();
            int arg2 = i->get_prox()->get_elemento();

            i->set_elemento(avalia_and(arg1, arg2));
            i->set_novo_prox(i->get_prox()->get_prox());
        }
    }

    for(Item *i = comeco; i < fim; i = i->get_prox()) {
        if(i->get_elemento() == '|') {
            int arg1 = i->get_ant()->get_elemento();
            int arg2 = i->get_prox()->get_elemento();

            i->set_elemento(avalia_or(arg1, arg2));
            i->set_novo_prox(i->get_prox()->get_prox());
        }
    }
    
    comeco = comeco->get_prox();
    comeco->set_novo_prox(fim->get_prox());
    return comeco->get_elemento(); 
}

int Avaliacao::avalia_or(int arg1, int arg2) {
    if(arg1 == 1 || arg2 == 1) {
        return 1;
    }
    return 0;
}

int Avaliacao::avalia_and(int arg1, int arg2) {
    if(arg1 == 1 && arg2 == 1) {
        return 1;
    }
    return 0;
}

/*int Avaliacao::avalia_expressao() {
    int i = 0;
    while(i < _expressao->getTamanho()) {
        switch (_expressao[i]) {
            case '&':
                _resultado = avalia_and(_expressao[i-1], _expressao[i+1]);
                break;
            
            case '|':
                _resultado = avalia_or(_expressao[i-1], _expressao[i+1]);
                break;

            case '~':
                _resultado = !_expressao[i+1];
                break;
            
            default:
                break;
        }
        i+=2;
    }
}*/

//int Avaliacao::avalia_parenteses() {}
