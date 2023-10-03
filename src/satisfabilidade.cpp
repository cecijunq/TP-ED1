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

char Satisfabilidade::resolve_problema(ItemArvore *no) {
    if(no->get_dir() != nullptr && no->get_esq() != nullptr) {
        char arg1 = resolve_problema(no->get_esq());
        char arg2 = resolve_problema(no->get_dir());

        if((no->get_quantificador() == 'a') && (arg1 == '1' && arg2 == '1')) {
            return '1';
        } else if((no->get_quantificador() == 'e') && (arg1 == '1' && arg2 == '1')) {
            return '1';
        } else if((no->get_quantificador() == 'e') && (arg1 == '1' || arg2 == '1')) {
            return '1';
        } else {
            return '0';
        }
    }

    Avaliacao aval = Avaliacao(_expressao, no->get_atributos());
    return aval.avalia_trecho();
}