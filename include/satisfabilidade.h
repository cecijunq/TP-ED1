#ifndef SATISFABILIDADE_H
#define SATISFABILIDADE_H

#include "./avaliacao.h"
#include "./item_arvore.h"
#include <vector>

class Satisfabilidade {
    private:
        ItemArvore *raiz;
        std::string _expressao;

    public:
        Satisfabilidade(std::string expressao, std::string atributos);
        ~Satisfabilidade();
        void Limpa(ItemArvore *no);
        void insere_recursivo(ItemArvore *aux);
        std::string resolve_problema(ItemArvore *no);
        ItemArvore *get_raiz();
        std::string exite_para_todo(ItemArvore *no, char elem);
};

#endif