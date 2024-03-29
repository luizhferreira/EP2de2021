#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <iostream>
#include <string>
using namespace std;

class Chat;

class Segmento{
    public:
    Segmento(int portaDeOrigem, int portaDeDestino, string dado);
    virtual ~Segmento();

    virtual int getPortaDeOrigem();
    virtual int getPortaDeDestino();
    virtual string getDado();
    virtual void imprimir();

    private:
    int portaDeOrigem;
    int portaDeDestino;
    string dado;
};

#endif // SEGMENTO_H
