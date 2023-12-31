#ifndef AVALIACAO_H
#define AVALIACAO_H

#include "./lista.h"


class parametros_invalidos {};
class elemento_invalido {};

class Avaliacao {
    private:
        int _tamanho;
        Lista stack;
        Lista operadores;

    public:
        Avaliacao(std::string expressao, std::string atributos);
        Avaliacao();
        //~Avaliacao();
        void Limpa();
        int precedence(char operador);
        void postfix(std::string expressao, std::string atributos);
        //Lista get_stack();
        char avalia_trecho();
        char avalia_or(char arg1, char arg2);
        char avalia_and(char arg1, char arg2);
        char avalia_not(char arg1);

};

#endif 