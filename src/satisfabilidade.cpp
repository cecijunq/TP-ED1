#include "../include/satisfabilidade.h"

Satisfabilidade::Satisfabilidade(std::string expressao, std::string atributos) {
    _expressao = expressao;
    tem_quantificador_existe = false;

    raiz = new ItemArvore(atributos);
    insere_recursivo(raiz);
}

void Satisfabilidade::Limpa(ItemArvore *no) {
    if(no!= nullptr){
        Limpa(no->get_esq());
        Limpa(no->get_dir());
        delete no;
    }
}

Satisfabilidade::~Satisfabilidade() {
    Limpa(raiz);
}

void Satisfabilidade::insere_recursivo(ItemArvore *aux) {
    int x = aux->muda_valor_quantificador();
    if(x == 1) {
        insere_recursivo(aux->get_esq());
        insere_recursivo(aux->get_dir());
    }
} // O(2^n)

int i = 0;
char Satisfabilidade::resolve_problema(ItemArvore *no) {
    if(no->get_dir() != nullptr && no->get_esq() != nullptr) {
        char arg1 = resolve_problema(no->get_esq());
        char arg2 = resolve_problema(no->get_dir());

        if((no->get_quantificador() == 'a') && (arg1 == '1' && arg2 == '1')) {
            char pos = no->get_esq()->get_pos_quantificador();

            if(no->get_esq()->get_atributos()[pos] == no->get_dir()->get_atributos()[pos]) {
                char elem_quantif = no->get_dir()->get_atributos()[pos];
                exite_para_todo(no, elem_quantif);
            } else {
                if(no->get_esq()->get_atributos()[pos] == 'a') {
                    std::string aux = no->get_atributos();
                    aux[pos] = no->get_dir()->get_atributos()[pos];
                    no->set_atributos(aux);
                } else if(no->get_dir()->get_atributos()[pos] == 'a') {
                    std::string aux = no->get_atributos();
                    aux[pos] = no->get_esq()->get_atributos()[pos];
                    no->set_atributos(aux);
                }
            }

            //i++;
            no->set_resultado('1');
            return '1';
            
        } else if((no->get_quantificador() == 'e') && (arg1 == '1' && arg2 == '1')) {
            tem_quantificador_existe = true;
            exite_para_todo(no, 'a');
            //i++;
            no->set_resultado('1');
            return '1';

        } else if((no->get_quantificador() == 'e') && (arg1 == '1')) {
            tem_quantificador_existe = true;

            int elem_pos = no->get_pos_quantificador();
            char elem_quantif = no->get_esq()->get_atributos()[elem_pos];
            exite_para_todo(no, elem_quantif);
            //i++;
            no->set_resultado('1');

            return '1';

        } else if((no->get_quantificador() == 'e') && (arg2 == '1')) {
            tem_quantificador_existe = true;
            int elem_pos = no->get_pos_quantificador();
            char elem_quantif = no->get_dir()->get_atributos()[elem_pos];
            exite_para_todo(no, elem_quantif);

            //i++;
            no->set_resultado('1');

            return '1';

        } else {
            no->set_resultado('0');
            return '0';
        }
    }

    Avaliacao aval = Avaliacao(_expressao, no->get_atributos());
    i++;
    no->set_resultado(aval.avalia_trecho());
    return aval.avalia_trecho();
} // O(2^n), t.q. n é número de quantificadores

void Satisfabilidade::exite_para_todo(ItemArvore *no, char elem) {
    std::string aux = no->get_atributos();
    int index_quantif = no->get_pos_quantificador();
    aux[index_quantif] = elem;
    no->set_atributos(aux);
} // O(n)

void Satisfabilidade::avalia_satisfabilidade() {
    resolve_problema(raiz);
    if(tem_quantificador_existe == true && raiz->get_resultado() == '1') {
        std::cout << raiz->get_resultado() << " " << raiz->get_atributos() << std::endl;
    } else {
        std::cout << raiz->get_resultado() << std::endl;
    }
}