#include "../include/avaliacao.h"

class ParametrosInvalidos {};

Avaliacao::Avaliacao(std::string expressao, std::string atributos) {
    if(atributos.size() > 10e6 || expressao.size() > 100) {
        throw ParametrosInvalidos();
    }

    _tamanho = 0;
    stack = new Lista();
    operadores = new Lista();
    postfixEval(expressao, atributos);
}

int Avaliacao::precedence(char operador) {
    switch (operador) {
    case '~':
        return 3;
    case '&':
        return 2;
    case '|':
        return 1;
    }
    return -1;
}

void Avaliacao::postfixEval(std::string expressao, std::string atributos) {
    Item *novo;

    for(unsigned int i = 0; i < expressao.size(); i++) {
        if(expressao[i] != ' ') {
            if(expressao[i] == '~' || expressao[i] == '&' || expressao[i] == '|' || expressao[i] == '(' || expressao[i] == ')') {

                if(operadores->get_inicio() == nullptr) {
                    novo = new Item(expressao[i], nullptr);
                    operadores->muda_inicio(novo);

                } else {
                    if(expressao[i] == ')') {
                        while(operadores->get_fim()!= nullptr) {
                            if(operadores->get_fim()->get_elemento() != '(') {
                                stack->get_fim()->set_novo_prox(operadores->get_fim());
                                operadores->muda_fim(operadores->get_fim()->get_ant());
                                stack->get_fim()->get_prox()->set_novo_ant(stack->get_fim());
                                stack->muda_fim(stack->get_fim()->get_prox());
                                if(operadores->get_fim() != nullptr)
                                    operadores->get_fim()->set_novo_prox(nullptr);
                            } else {
                                operadores->muda_fim(operadores->get_fim()->get_ant());
                                operadores->get_fim()->set_novo_prox(nullptr);
                            }
                        }
                        if(operadores->get_fim() == nullptr) operadores->muda_inicio(nullptr);
                    }
                    else {
                        novo = new Item(expressao[i], operadores->get_fim());
                        operadores->get_fim()->set_novo_prox(novo);
                    }

                }
                operadores->muda_fim(novo);
                Item *aux = operadores->get_fim();
                while((aux->get_ant() != nullptr) && (aux->get_elemento()) < precedence(aux->get_ant()->get_elemento())) {
                    Item *tmp = aux->get_ant();
                    aux->set_novo_prox(tmp);
                    tmp->set_novo_prox(nullptr);
                    aux->set_novo_ant(tmp->get_ant());
                    tmp->get_ant()->set_novo_prox(aux);
                    tmp->set_novo_ant(aux);
                    if(aux->get_ant() == nullptr) {
                        operadores->muda_inicio(aux);
                    }
                    operadores->muda_fim(tmp);
                }

            } else {
                
                if(stack->get_inicio() == nullptr) {
                    novo = new Item(atributos[expressao[i] - '0'], nullptr);
                    stack->muda_inicio(novo);
                } else {
                    novo = new Item(atributos[expressao[i] - '0'], stack->get_fim());
                    stack->get_fim()->set_novo_prox(novo);
                }
                stack->muda_fim(novo);

            }
        }
    }
    
    while(operadores->get_fim() != nullptr) {
        stack->get_fim()->set_novo_prox(operadores->get_fim());
        operadores->muda_fim(operadores->get_fim()->get_ant());
        stack->get_fim()->get_prox()->set_novo_ant(stack->get_fim());
        stack->muda_fim(stack->get_fim()->get_prox());
        if(operadores->get_fim() != nullptr)
            operadores->get_fim()->set_novo_prox(nullptr);
        else
            operadores->muda_inicio(nullptr);

    }
}

char Avaliacao::avalia_trecho() {
    Item *arg1, *arg2;
    for (Item *aux = stack->get_inicio(); aux != nullptr; aux = aux->get_prox()) {
        switch (aux->get_elemento()) {
            case '~':
                arg1 = aux->get_ant();
                
                aux->set_elemento(avalia_not(arg1->get_elemento()));
                if(arg1->get_ant() != nullptr)
                    arg1->get_ant()->set_novo_prox(aux);
                aux->set_novo_ant(arg1->get_ant());
                break;

            case '&':
                arg1 = aux->get_ant();
                arg2 = arg1->get_ant();

                aux->set_elemento(avalia_and(arg1->get_elemento(), arg2->get_elemento()));
                aux->set_novo_ant(arg2->get_ant());
                if(arg2->get_ant() != nullptr)
                    arg2->get_ant()->set_novo_prox(aux);
                else
                    stack->muda_inicio(aux);
                break;
            
            case '|':
                arg1 = aux->get_ant();
                arg2 = arg1->get_ant();

                aux->set_elemento(avalia_or(arg1->get_elemento(), arg2->get_elemento()));
                aux->set_novo_ant(arg2->get_ant());
                if(arg2->get_ant() != nullptr)
                    arg2->get_ant()->set_novo_prox(aux);
                else
                    stack->muda_inicio(aux);
                break;
            default:
                continue;
        }
    }
    return stack->get_inicio()->get_elemento();
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