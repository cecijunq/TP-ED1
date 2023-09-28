#include "../include/avaliacao.h"

class ParametrosInvalidos {};

Avaliacao::Avaliacao(std::string expressao, std::string atributos) {
    if(atributos.size() > 10e6 || expressao.size() > 100) {
        throw ParametrosInvalidos();
    }

    stack = new Lista();
    operadores = new Lista();
    postfixEval(expressao, atributos);

    /*
    int j = 0;
    for(unsigned int i = 0; i < expressao.size(); i++) {
        if(expressao[i] != ' ') {
            ////std::cout << expressao[i] << std::endl;
            if(expressao[i] == '~' || expressao[i] == '&' || expressao[i] == '|' || expressao[i] == '(' || expressao[i] == ')') {
                //std::cout << expressao[i] << " 21" << std::endl;
                if(operadores->get_inicio() == nullptr) {
                    //std::cout << expressao[i] << " 23" << std::endl;
                    novo = new Item(expressao[i], nullptr);
                    operadores->muda_inicio(novo);
                    operadores->muda_fim(novo);

                } else {
                    //std::cout << expressao[i] << " 29" << std::endl;
                    if((expressao[i] == '|' && (operadores->get_fim()->get_elemento() == '&' || operadores->get_fim()->get_elemento() == '~')) || (expressao[i] == '&' && operadores->get_fim()->get_elemento() == '~')) {
                        //std::cout << expressao[i] << " 31" << std::endl;
                        novo = new Item(expressao[i], operadores->get_fim()->get_ant());
                        novo->set_novo_prox(operadores->get_fim());
                        if(operadores->get_fim()->get_ant() == nullptr) {
                            operadores->muda_inicio(novo);
                        }
                        operadores->get_fim()->set_novo_ant(novo);

                    } else {
                        //std::cout << expressao[i] << " 40" << std::endl;
                        novo = new Item(expressao[i], operadores->get_fim());
                        operadores->get_fim()->set_novo_prox(novo);
                        operadores->muda_fim(novo);
                    }
                }

            } else {
                //std::cout << expressao[i] << " 48" << std::endl;
                if(operadores->get_inicio() != nullptr && operadores->get_fim()->get_elemento() == ')') {
                    operadores->get_fim()->get_ant()->set_novo_prox(nullptr);
                    operadores->muda_fim(operadores->get_fim()->get_ant());
                    //std::cout << expressao[i] << " 50" << std::endl;
                    for(Item *aux = operadores->get_fim(); aux != nullptr; aux = aux->get_ant()) {
                        if(aux->get_elemento() != '(') {
                            //std::cout << expressao[i] << " 53" << std::endl;
                            aux->set_novo_ant(stack->get_fim());
                            stack->get_fim()->set_novo_prox(aux);
                            aux->get_ant()->set_novo_prox(aux->get_prox());
                            stack->muda_fim(aux);
                        } else {
                            aux->get_ant()->set_novo_prox(nullptr);
                            stack->muda_fim(aux);
                        }
                    }
                    //operadores->muda_fim(nullptr);
                    //operadores->muda_inicio(nullptr);
                    j = 0;
                }

                if(stack->get_inicio() == nullptr) {
                    //std::cout << expressao[i] << " 65" << std::endl;
                        novo = new Item(atributos[expressao[i] - '0'], nullptr);
                        stack->muda_inicio(novo);
                        stack->muda_fim(novo);

                } else {
                    //std::cout << expressao[i] << " 71" << std::endl;
                    novo = new Item(atributos[expressao[i] - '0'], stack->get_fim());
                }
                j++;

                if(j == 2) {
                    //std::cout << expressao[i] << " 77" << std::endl;
                    for(Item *aux = operadores->get_fim(); aux != nullptr; aux = aux->get_ant()) {
                            //std::cout << expressao[i] << " 80" << std::endl;
                            if(aux->get_ant() != nullptr)
                                aux->get_ant()->set_novo_prox(nullptr);
                            //std::cout << expressao[i] << " 81" << std::endl;
                            operadores->muda_fim(aux->get_ant());
                            //std::cout << expressao[i] << " 81" << std::endl;
                            //if(operadores->get_fim() != nullptr)
                            //    operadores->get_fim()->set_novo_prox(nullptr);
                            //std::cout << expressao[i] << " 83" << std::endl;
                            aux->set_novo_ant(stack->get_fim());
                            //std::cout << expressao[i] << " 85" << std::endl;
                            stack->get_fim()->set_novo_prox(aux);
                            //std::cout << expressao[i] << " 86" << std::endl;
                            stack->muda_fim(aux);
                            //std::cout << expressao[i] << " 87" << std::endl;
                        //if(aux->get_elemento() != '(') {}
                    }
                    //operadores->muda_fim(nullptr);
                    operadores->muda_inicio(nullptr);
                    j = 0;
                    //std::cout << expressao[i] << " 90" << std::endl;
                }
            }
        }
    } */
    //_expressao = new Lista(expressao, atributos);
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
                    /*
                    if(expressao[i] != '(' && expressao[i] != ')' && operadores->get_fim()->get_elemento() != '(') {
                        while(precedence(expressao[i]) < precedence(operadores->get_fim()->get_elemento())) {
                            std::cout << "teste" << std::endl;
                            novo = new Item(expressao[i], operadores->get_fim()->get_ant());
                            novo->set_novo_prox(operadores->get_fim());
                            if(operadores->get_fim()->get_ant() == nullptr) {
                                operadores->muda_inicio(novo);
                            }
                            operadores->get_fim()->set_novo_ant(novo);
                        }
                    }
                    */
                    

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
                    std::cout << "teste" << std::endl;
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
                /*
                Item *aux = operadores->get_fim();
                while(precedence(aux->get_elemento()) < precedence(aux->get_ant()->get_elemento())) {
                    std::cout << "teste" << std::endl;
                    //Item *ultimo = aux;
                    Item *penultipo = aux->get_ant();
                    //novo = new Item(expressao[i], operadores->get_fim()->get_ant());
                    aux->set_novo_ant(penultipo->get_ant());
                    aux->set_novo_prox(penultipo);
                    if(aux->get_ant() != nullptr) {
                        aux->get_ant()->set_novo_prox(aux);
                    } else {
                        operadores->muda_inicio(novo);
                    }
                    penultipo->set_novo_ant(aux);
                    penultipo->set_novo_prox(nullptr);
                    operadores->muda_fim(penultipo);
                }
                */

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

            
            //if(operadores->get_fim()->get_elemento() != '(' && expressao[i] != ')' && operadores->get_fim()->get_elemento() != '(') {}

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

/*
char Avaliacao::percorre_expressao() {
    //Pilha operadores_pos = Pilha();
    //Pilha atributos_pos = Pilha();
    Pilha parenteses_pos = Pilha();
    for(Item *aux = _expressao->get_inicio(); aux != nullptr; aux = aux->get_prox()) {
        if(aux->get_elemento() == '(' || aux->get_elemento() == '~' || aux->get_elemento() == '&' || aux->get_elemento() == '|') {
            operadores_pos.empilha(aux);

        } else if(aux->get_elemento() == ')') {
            Item *comeco = parenteses_pos.desempilha();
            avalia_trecho(comeco, aux);

            if (comeco->get_prox() == nullptr) {
                _expressao->muda_fim(comeco);
            }
            if (comeco->get_ant() == nullptr) {
                _expressao->muda_inicio(comeco);
            }
        } else {
            atributos_pos.empilha(aux);
        }
    } 
    
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
*/

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
    
    //Item *arg1, *arg2;
    
    /*
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

        ////std::cout << "entrou 135" << std::endl;
        ////std::cout << "Endereço comeco: " << comeco << std::endl;
        ////std::cout << "Valor comeco: " << comeco->get_elemento() << std::endl;
        ////std::cout << "Endereço prox: " << comeco->get_prox() << std::endl;
        ////std::cout << "Valor prox: " << comeco->get_prox()->get_elemento() << std::endl;
        ////std::cout << "Endereço ant: " << comeco->get_ant() << std::endl;
        ////std::cout << "Valor ant: " << comeco->get_ant()->get_elemento() << std::endl; 
    }
    */
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