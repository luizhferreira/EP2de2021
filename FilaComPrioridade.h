#ifndef FILACOMPRIORIDADE_H
#define FILACOMPRIORIDADE_H

#include "Fila.h"

class RoteadorComQoS;

class FilaComPrioridade:public Fila{
    public:
    FilaComPrioridade(int tamanho);
    virtual ~FilaComPrioridade();

    using Fila::enqueue;
    virtual void enqueue(Datagrama* d, bool prioritario);

    private:
    list <Datagrama*>::iterator it;
};

#endif // FILACOMPRIORIDADE_H
