#ifndef ITEM_ARVORE_H
#define ITEM_ARVORE_H

#include "./lista.h"
#include "./avaliacao.h"

class ItemArvore {
    private:
        std::string _atributos;
        ItemArvore *esq;
        ItemArvore *dir;
        char resultado;
        char quantificador;
        int pos_quantificador;

    public:
        ItemArvore(std::string atributos);
        int muda_valor_quantificador();
        ItemArvore *get_esq();
        ItemArvore *get_dir();
        char get_resultado();
        char get_quantificador();
        std::string get_atributos();
        int get_pos_quantificador();
        void set_atributos(std::string novo_atributos);
        void set_resultado(char valor);
};

#endif