#include "../include/item_arvore.h"

ItemArvore::ItemArvore(std::string atributos) {
    _atributos = atributos;
    esq = nullptr;
    dir = nullptr;
}

int ItemArvore::muda_valor_quantificador() {
    for(int i = 0; i < _atributos.size(); i++) {
        if(_atributos[i] == 'a' || _atributos[i] == 'e') {
            quantificador = _atributos[i];

            _atributos[i] = '0';
            ItemArvore *ramo_esq = new ItemArvore(_atributos);
            
            _atributos[i] = '1';
            ItemArvore *ramo_dir = new ItemArvore(_atributos);

            _atributos[i] = quantificador;
            esq = ramo_esq;
            dir = ramo_dir;

            return 1;
        }
    }
    return 0;
    /*
    Avaliacao tmp_esq = Avaliacao(get_avaliacao().get_stack());
    Avaliacao tmp_dir = Avaliacao(get_avaliacao().get_stack());
    int i = 0;
    for(Item *aux = _item.get_stack().get_inicio(); aux != nullptr; aux = aux->get_prox()) {
        i++;
        if(aux->get_elemento() == 'a' || aux->get_elemento() == 'e') {
            quantificador = aux->get_elemento();


            //aux->set_elemento('0');
            //ItemArvore *esq = new ItemArvore(get_avaliacao());
            
            //aux->set_elemento('1');
            //ItemArvore *dir = new ItemArvore(get_avaliacao());

            tmp_esq.get_stack().set_nesimo_item(i-1, '0');
            tmp_dir.get_stack().set_nesimo_item(i-1, '1');

            ItemArvore *esq_ramo = new ItemArvore(tmp_esq);
            ItemArvore *dir_ramo = new ItemArvore(tmp_dir);

            for(Item *i = tmp_esq.get_stack().get_inicio(); i != nullptr; i = i->get_prox()) {
                std::cout << i->get_elemento() << " ";
            }
            std::cout << std::endl;
            for(Item *i = tmp_dir.get_stack().get_inicio(); i != nullptr; i = i->get_prox()) {
                std::cout << i->get_elemento() << " ";
            }

            esq = esq_ramo;
            dir = dir_ramo;

            return 1;
        }
    }
    return 0;
    */
}

ItemArvore *ItemArvore::get_esq() {
    return esq;
}

ItemArvore *ItemArvore::get_dir() {
    return dir;
}

char ItemArvore::get_resultado() {
    return resultado;
}

char ItemArvore::get_quantificador() {
    return quantificador;
}

std::string ItemArvore::get_atributos() {
    return _atributos;
}

void ItemArvore::set_atributos(std::string novo_atributos) {
    _atributos = novo_atributos;
}