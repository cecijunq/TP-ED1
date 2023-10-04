#ifndef ITEM_ARVORE_H
#define ITEM_ARVORE_H

//#include "./tipo_item.h"
#include "./lista.h"
#include "./avaliacao.h"

class ItemArvore {
    private:
        //Avaliacao _item;
        std::string _atributos;
        ItemArvore *esq;
        ItemArvore *dir;
        char resultado;
        char quantificador;

    public:
        //ItemArvore(Avaliacao _item);
        ItemArvore(std::string atributos);
        //Avaliacao get_avaliacao();
        int muda_valor_quantificador();
        ItemArvore *get_esq();
        ItemArvore *get_dir();
        char get_resultado();
        char get_quantificador();
        std::string get_atributos();
        void set_atributos(std::string novo_atributos);

};

#endif