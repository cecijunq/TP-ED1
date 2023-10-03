#ifndef SATISFABILIDADE_H
#define SATISFABILIDADE_H

#include "./avaliacao.h"
#include "./item_arvore.h"
#include <vector>

class Satisfabilidade {
    private:
        //Avaliacao *a;
        ItemArvore *raiz;
        std::string _expressao;

    public:
        Satisfabilidade(std::string expressao, std::string atributos);
        void insere_recursivo(ItemArvore *aux);
        char resolve_problema(ItemArvore *no);
        ItemArvore *get_raiz();
};

#endif