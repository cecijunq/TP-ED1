#include "../include/avaliacao.h"

Avaliacao::Avaliacao(std::string expressao, std::string atributos) {
    if(expressao.size() > 10e6 || atributos.size() > 100) {
        throw parametros_invalidos();
    }

    _tamanho = 0;
    stack = Lista();
    operadores = Lista();
    postfix(expressao, atributos);
}

Avaliacao::Avaliacao() {}

Avaliacao::~Avaliacao() {
    Limpa();
}

void Avaliacao::Limpa() {
    Item *aux = stack.get_inicio();
    while (aux != nullptr) {
        stack.muda_inicio(aux->get_prox());
        delete aux;
        aux = stack.get_inicio();
    }
    _tamanho = 0;
}

int Avaliacao::precedence(char operador) {
    //std::cout << operador << " precedence" << std::endl;
    if(operador == '~') {
        return 3;
    } else if(operador == '&') {
        return 2;
    } else if(operador == '|') {
        return 1;
    }
    return 0;
}

void Avaliacao::postfix(std::string expressao, std::string atributos) {
    Item *novo;

    for(unsigned int i = 0; i < expressao.size(); i++) {
        if(expressao[i] != ' ') {
            if(expressao[i] == '~' || expressao[i] == '&' || expressao[i] == '|' || expressao[i] == '(' || expressao[i] == ')') {

                if(operadores.get_inicio() == nullptr) {
                    novo = new Item(expressao[i], nullptr);
                    operadores.muda_inicio(novo);
                    operadores.muda_fim(novo);

                } else {
                    if(expressao[i] == ')') {
                        while(operadores.get_fim()->get_elemento() != '(') {
                                _tamanho++;
                                stack.get_fim()->set_novo_prox(operadores.get_fim());
                                operadores.muda_fim(operadores.get_fim()->get_ant());
                                stack.get_fim()->get_prox()->set_novo_ant(stack.get_fim());
                                stack.muda_fim(stack.get_fim()->get_prox());
                                if(operadores.get_fim() != nullptr)
                                    operadores.get_fim()->set_novo_prox(nullptr);

                        }
                        operadores.muda_fim(operadores.get_fim()->get_ant());
                        if(operadores.get_fim() != nullptr && operadores.get_fim()->get_elemento() == '~') {
                            stack.get_fim()->set_novo_prox(operadores.get_fim());
                            operadores.muda_fim(operadores.get_fim()->get_ant());
                            stack.get_fim()->get_prox()->set_novo_ant(stack.get_fim());
                            stack.muda_fim(stack.get_fim()->get_prox());
                        }
                        if(operadores.get_fim() != nullptr) {
                            operadores.get_fim()->set_novo_prox(nullptr);
                        } else {
                            operadores.muda_inicio(nullptr);
                        }

                    } else {
                        novo = new Item(expressao[i], operadores.get_fim());
                        operadores.get_fim()->set_novo_prox(novo);
                        operadores.muda_fim(novo);
                    }

                }
                Item *aux = operadores.get_fim();
                while((aux != nullptr && aux->get_ant() != nullptr) && (aux->get_ant()->get_elemento() != '(' && aux->get_elemento() != '(') && precedence(aux->get_elemento()) < precedence(aux->get_ant()->get_elemento())) {
                    
                    Item *tmp = aux->get_ant();
                    
                    stack.get_fim()->set_novo_prox(tmp);
                    aux->set_novo_ant(tmp->get_ant());
                    if(tmp->get_ant() != nullptr)
                        tmp->get_ant()->set_novo_prox(aux);
                    else
                        operadores.muda_inicio(aux);
                    tmp->set_novo_ant(stack.get_fim());
                    stack.muda_fim(tmp);

                }
                
            } else if(expressao[i] >= '0' && expressao[i] <= '9') {
                std::string atrib;
                if((expressao[i+1] >= '0' && expressao[i+1] <= '9') || (expressao[i+1] == ' ' && expressao[i+2] >= '0' && expressao[i+2] <= '9')) {
                    
                    atrib.insert(atrib.end(),expressao[i]);
                    atrib.insert(atrib.end(),expressao[i+1]);
                    i++;
                } else {
                    atrib = expressao[i];
                }
                if(stoi(atrib) >= atributos.size()) throw elemento_invalido();
                _tamanho++;
                if(stack.get_inicio() == nullptr) {
                    novo = new Item(atributos[stoi(atrib)], nullptr);
                    stack.muda_inicio(novo);
                } else {
                    novo = new Item(atributos[stoi(atrib)], stack.get_fim());
                    stack.get_fim()->set_novo_prox(novo);
                }
                stack.muda_fim(novo);
                atrib.clear();

            } else {
                throw elemento_invalido();
            }
        }
    }
  
    while(operadores.get_fim() != nullptr) {
        stack.get_fim()->set_novo_prox(operadores.get_fim());
        operadores.muda_fim(operadores.get_fim()->get_ant());
        stack.get_fim()->get_prox()->set_novo_ant(stack.get_fim());
        stack.muda_fim(stack.get_fim()->get_prox());
        if(operadores.get_fim() != nullptr)
            operadores.get_fim()->set_novo_prox(nullptr);
        else
            operadores.muda_inicio(nullptr);
        _tamanho++;
    }
}

char Avaliacao::avalia_trecho() {
    Item *arg1, *arg2;
    for (Item *aux = stack.get_inicio(); aux != nullptr; aux = aux->get_prox()) {
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
                    stack.muda_inicio(aux);
                break;
            
            case '|':
                arg1 = aux->get_ant();
                arg2 = arg1->get_ant();

                aux->set_elemento(avalia_or(arg1->get_elemento(), arg2->get_elemento()));
                aux->set_novo_ant(arg2->get_ant());
                if(arg2->get_ant() != nullptr)
                    arg2->get_ant()->set_novo_prox(aux);
                else
                    stack.muda_inicio(aux);
                break;
            default:
                continue;
        }
    }
    return stack.get_inicio()->get_elemento();
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