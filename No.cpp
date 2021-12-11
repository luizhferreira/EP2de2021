#include "No.h"

No::No(int endereco):
    endereco(endereco), fila(new Fila(TAMANHO_FILA)){
}

No::No(int endereco, Fila* fila):
    endereco(endereco), fila(fila){
}

No::~No(){
    delete fila;
}

int No::getEndereco(){
    return endereco;
}

void No::receber(Datagrama* d){
    if (fila->getSize() < TAMANHO_FILA) {
       fila->enqueue(d);
    } else
        cout << "\tFila em " << endereco << " estourou" << endl;
}

void No::imprimir(){
}
