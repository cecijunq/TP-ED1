#ifndef SATISFABILIDADE_H
#define SATISFABILIDADE_H

#include "./avaliacao.h"

class Satisfabilidade {
    private:
        Avaliacao *a;

    public:
        Satisfabilidade(std::string expressao, std::string atributos);
        
};

#endif