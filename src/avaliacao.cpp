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
    //std::cout << "entrou 15" << std::endl;
    Pilha parenteses_pos = Pilha();
    /*
    Pilha operadores = Pilha();
    Pilha atributos = Pilha();
    
    int i = 0;
    for(Item *aux = _expressao->get_inicio(); aux != nullptr; aux = aux->get_prox()) {
        std::cout << aux->get_elemento() << std::endl;
        if(aux->get_elemento() == '(' || aux->get_elemento() == '~' || aux->get_elemento() == '&' || aux->get_elemento() == '|') {
            std::cout << "entrou 20" << std::endl;
            //parenteses_pos.empilha(aux->get_elemento());
            operadores.empilha(aux);
            i++;

        } else if(aux->get_elemento() == ')') {
            std::cout << "entrou 25" << std::endl;
            Item *comeco = atributos.desempilha();
            std::cout << comeco->get_elemento() << std::endl;
            std::cout << comeco << std::endl;
            avalia_trecho(comeco, aux);

            if (comeco->get_prox() == nullptr) {
                _expressao->muda_fim(comeco);
            }
            if (comeco->get_ant() == nullptr) {
                _expressao->muda_inicio(comeco);
            }
        } else {
            atributos.empilha(aux);
            i++;
        }
    } 
    */
    for(Item *aux = _expressao->get_inicio(); aux != nullptr; aux = aux->get_prox()) {
        //std::cout << aux->get_elemento() << std::endl;
        if(aux->get_elemento() == '(') {
            //std::cout << "entrou 20" << std::endl;
            //parenteses_pos.empilha(aux->get_elemento());
            parenteses_pos.empilha(aux);

        } else if(aux->get_elemento() == ')') {
            //std::cout << "entrou 25" << std::endl;
            Item *comeco = parenteses_pos.desempilha();
            //std::cout << comeco->get_elemento() << std::endl;
            //std::cout << comeco << std::endl;
            avalia_trecho(comeco, aux);

            if (comeco->get_prox() == nullptr) {
                _expressao->muda_fim(comeco);
            }
            if (comeco->get_ant() == nullptr) {
                _expressao->muda_inicio(comeco);
            }
        }
    }
    //for(Item *i = _expressao->get_inicio(); i != nullptr; i = i->get_prox()) {
        //std::cout << i->get_elemento() << " ";
    //}
    //std::cout << "L71: " << _expressao->get_inicio()->get_elemento() << std::endl;
    //std::cout << "L71: " << _expressao->get_fim()->get_elemento() << std::endl;
    avalia_trecho(_expressao->get_inicio(), _expressao->get_fim());
    return _expressao->get_inicio()->get_elemento();
}


void Avaliacao::avalia_trecho(Item *comeco, Item *fim) {
    Item *arg1, *arg2;
    //std::cout << "entrou 44" << std::endl;
    //std::cout << comeco->get_elemento() << std::endl;
    //std::cout << comeco->get_prox()->get_elemento() << std::endl;
    
    
    for(Item *i = comeco; i != fim; i = i->get_prox()) {
        //if(i == nullptr) break;
        //std::cout << i->get_elemento() << std::endl;
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
                arg2->get_prox()->set_novo_ant(i);
                i->set_novo_prox(arg2->get_prox());
                break;
            
            case '|':
                arg1 = i->get_ant();
                arg2 = i->get_prox();

                arg1->set_elemento(avalia_or(arg1->get_elemento(), arg2->get_elemento()));
                i = arg1;
                arg2->get_prox()->set_novo_ant(i);
                i->set_novo_prox(arg2->get_prox());
                break;
        }
    }
    Item *novo_anterior = comeco->get_ant();
    Item *novo_atual = comeco->get_prox();
    comeco->set_elemento(comeco->get_prox()->get_elemento());
    comeco->set_novo_prox(fim->get_prox()); 
    std::cout << "Endereço comeco: " << comeco << std::endl;
    std::cout << "Valor comeco: " << comeco->get_elemento() << std::endl;
    std::cout << "Endereço prox: " << comeco->get_prox() << std::endl;
    std::cout << "Valor prox: " << comeco->get_prox()->get_elemento() << std::endl;
    std::cout << "Endereço ant: " << comeco->get_ant() << std::endl;
    std::cout << "Valor ant: " << comeco->get_ant()->get_elemento() << std::endl;
    //return comeco->get_elemento(); 
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