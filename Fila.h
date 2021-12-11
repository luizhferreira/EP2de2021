#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"
#include <stdexcept>
#include <list>
#include <vector>

class Fila {
    protected:
    int tamanho;
    list <Datagrama*> *fila;

    public:
    Fila(int tamanho);
    virtual ~Fila();

    virtual void enqueue(Datagrama* d);
    virtual Datagrama* dequeue();
    virtual bool isEmpty();
    virtual int getSize();

    virtual void imprimir();
};

#endif // FILA_H
