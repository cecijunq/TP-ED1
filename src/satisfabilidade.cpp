#include "../include/satisfabilidade.h"

Satisfabilidade::Satisfabilidade(std::string expressao, std::string atributos) {
    _expressao = expressao;

    raiz = new ItemArvore(atributos);
    insere_recursivo(raiz);
}

ItemArvore *Satisfabilidade::get_raiz() {
    return raiz;
}

void Satisfabilidade::insere_recursivo(ItemArvore *aux) {
    int x = aux->muda_valor_quantificador();
    if(x == 1) {
        insere_recursivo(aux->get_esq());
        insere_recursivo(aux->get_esq());
    }
}

std::string Satisfabilidade::resolve_problema(ItemArvore *no) {
    if(no->get_dir() != nullptr && no->get_esq() != nullptr) {
        std::string arg1 = resolve_problema(no->get_esq());
        std::string arg2 = resolve_problema(no->get_dir());

        if((no->get_quantificador() == 'a') && (arg1 == "1" && arg2 == "1")) {
            return "1";
        } else if((no->get_quantificador() == 'e') && (arg1 == "1" && arg2 == "1")) {
            return exite_para_todo(no, 'a');
        } else if((no->get_quantificador() == 'e') && (arg1 == "1")) {
            no->set_atributos(no->get_esq()->get_atributos());
            return "1 " + no->get_atributos();
        } else if((no->get_quantificador() == 'e') && (arg2 == "1")) {
            no->set_atributos(no->get_dir()->get_atributos());
            return "1 " + no->get_atributos();
        } else {
            return "0";
        }
    }

    Avaliacao aval = Avaliacao(_expressao, no->get_atributos());
    return std::string(1, aval.avalia_trecho());
}

std::string Satisfabilidade::exite_para_todo(ItemArvore *no, char elem) {
    std::string aux = no->get_atributos();
    for(int i = 0; i < aux.size(); i++) {
        if(aux[i] == 'e') {
            aux[i] = elem;
            no->set_atributos(aux);
            break;
        }
    }
    return "1 " + no->get_atributos();
}