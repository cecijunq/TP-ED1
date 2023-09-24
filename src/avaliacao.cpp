#include "../include/avaliacao.h"
#include <regex>
#include <vector>

class ParametrosInvalidos {};

Avaliacao::Avaliacao(std::string expressao, std::string atributos) {
    if(atributos.size() > 10e6 || expressao.size() > 100) {
        throw ParametrosInvalidos();
    }
    _expressao = new Lista(expressao, atributos);
}

char Avaliacao::percorre_expressao() {
    Pilha parenteses_pos = Pilha();
    for(Item *aux = _expressao->get_inicio(); aux != nullptr; aux = aux->get_prox()) {
        if(aux->get_elemento() == '(') {
            parenteses_pos.empilha(aux);

        } else if(aux->get_elemento() == ')') {
            Item *comeco = parenteses_pos.desempilha();
            avalia_trecho(comeco, aux);

            if (comeco->get_prox() == nullptr) {
                _expressao->muda_fim(comeco);
            }
            if (comeco->get_ant() == nullptr) {
                _expressao->muda_inicio(comeco);
            }
        }
    }
    avalia_trecho(_expressao->get_inicio(), _expressao->get_fim());
    return _expressao->get_inicio()->get_elemento();
}


void Avaliacao::avalia_trecho(Item *comeco, Item *fim) {
    Item *arg1, *arg2;
    
    for(Item *i = comeco; i != fim->get_prox(); i = i->get_prox()) {
        switch (i->get_elemento()) {
            case '~':
                arg1 = i->get_prox();
                
                i->set_elemento(avalia_not(arg1->get_elemento()));
                arg1->get_prox()->set_novo_ant(i);
                i->set_novo_prox(arg1->get_prox());
                break;

            case '&':
                arg1 = i->get_ant();
                arg2 = i->get_prox();

                arg1->set_elemento(avalia_and(arg1->get_elemento(), arg2->get_elemento()));
                i = arg1;
                if(arg2->get_prox() != nullptr)
                    arg2->get_prox()->set_novo_ant(i);
                i->set_novo_prox(arg2->get_prox());

                break;
            
            case '|':
                arg1 = i->get_ant();
                arg2 = i->get_prox();

                arg1->set_elemento(avalia_or(arg1->get_elemento(), arg2->get_elemento()));
                i = arg1;
                if(arg2->get_prox() != nullptr)
                    arg2->get_prox()->set_novo_ant(i);
                i->set_novo_prox(arg2->get_prox());
                break;
        }
    }
    if(comeco->get_prox() != nullptr) {
        comeco->set_elemento(comeco->get_prox()->get_elemento());
        comeco->set_novo_prox(fim->get_prox());

        //std::cout << "entrou 135" << std::endl;
        //std::cout << "Endereço comeco: " << comeco << std::endl;
        //std::cout << "Valor comeco: " << comeco->get_elemento() << std::endl;
        //std::cout << "Endereço prox: " << comeco->get_prox() << std::endl;
        //std::cout << "Valor prox: " << comeco->get_prox()->get_elemento() << std::endl;
        //std::cout << "Endereço ant: " << comeco->get_ant() << std::endl;
        //std::cout << "Valor ant: " << comeco->get_ant()->get_elemento() << std::endl; 
    }
}

char Avaliacao::avalia_not(char arg1) {
    if(arg1 == '1') {
        return '0';
    }
    return '1';
}

char Avaliacao::avalia_or(char arg1, char arg2) {
    if(arg1 == '1' || arg2 == '1') {
        return '1';
    }
    return '0';
}

char Avaliacao::avalia_and(char arg1, char arg2) {
    if(arg1 == '1' && arg2 == '1') {
        return '1';
    }
    return '0';
}