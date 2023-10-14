#ifndef SATISFABILIDADE_H
#define SATISFABILIDADE_H

#include "./avaliacao.h"
#include "./item_arvore.h"

class Satisfabilidade {
    private:
        ItemArvore *raiz;
        std::string _expressao;
        bool tem_quantificador_existe;

    public:
        Satisfabilidade(std::string expressao, std::string atributos);
        ~Satisfabilidade();
        void Limpa(ItemArvore *no);
        void insere_recursivo(ItemArvore *aux);
        char resolve_problema(ItemArvore *no);
        void exite_para_todo(ItemArvore *no, char elem, ItemArvore *anterior);
        void avalia_satisfabilidade();
};

#endif