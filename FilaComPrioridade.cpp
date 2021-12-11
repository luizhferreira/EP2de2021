#include "FilaComPrioridade.h"

FilaComPrioridade::FilaComPrioridade(int tamanho):Fila(tamanho){
    if (tamanho <= 0) {
        throw new invalid_argument("Tamanho invalido");
    } else
        it = fila->begin();
}

FilaComPrioridade::~FilaComPrioridade(){
}

void FilaComPrioridade::enqueue(Datagrama* d, bool prioritario){
    unsigned j = tamanho;
    if (fila->size() >= j) {
        throw new overflow_error("A fila com prioridade esta cheia");
    }
    if (prioritario==true) {
        fila->insert(++it, d);
        --it;
    } else
        fila->push_back(d);
}
