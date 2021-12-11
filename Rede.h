#ifndef REDE_H
#define REDE_H

#include "Hospedeiro.h"

class Rede {
    private:
    list <No*> *no;
    int tamanho;

    public:
    Rede();
    virtual ~Rede();

    virtual void adicionar(No* n);
    virtual No* getNo(int endereco);
    virtual list<No*>* getNos();
    virtual list<Hospedeiro*>* getHospedeiros();

    virtual void imprimir();
};

#endif // REDE_H
