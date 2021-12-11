#include "Fila.h"

Fila::Fila(int tamanho){
    if (tamanho <= 0) {
        throw new invalid_argument("Valor invalido");
    } else {
        this->tamanho = tamanho;
        fila = new list <Datagrama*>();
    }
}

Fila::~Fila(){
    while (!fila->empty()) {
        Datagrama *ultimo = fila->back();
        fila->pop_back();
        delete ultimo;
    }
    delete fila;
}

Datagrama*Fila::dequeue(){
    unsigned m = fila->size();
    if (m > 0) {
        Datagrama *Deletado = fila->front();
        fila->pop_front();
        return Deletado;
    } else
        throw new underflow_error("A fila esta vazia");
}

void Fila::enqueue(Datagrama* d){
    unsigned p = tamanho;
    if (fila->size() < p) {
        fila->push_back(d);
    } else
        throw new overflow_error("A fila esta cheia");
}

int Fila::getSize(){
    return fila->size();
}

bool Fila::isEmpty(){
    return fila->empty();
}

void Fila::imprimir(){
    list <Datagrama*>::iterator a = fila->begin();
    if (!fila->empty()) {
        cout << "(" << (*a)->getSegmento()->getDado();
        ++a;
        while (a != fila->end()) {
            cout << ", " << (*a)->getSegmento()->getDado();
            ++a;
        } cout << ")" << endl;
    }
}
