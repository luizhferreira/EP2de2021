#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "Rede.h"

class Agendador{
    private:
    int instanteInicial;
    Rede* rede;
    int tamanho;
    Evento** eventosAgendados;
    int elementosAgendados;

    int *ordemAgendamento;
    int agendamentos;

    int particao (Evento** &A, int* &O, int in, int f);
    void quickSort (Evento** &A, int* &O, int in, int f);

    int inicio;
    int fim;

    void enqueue(Evento* e);
    void dequeue();

    public:
    Agendador(int instanteInicial, Rede* rede, int tamanho);
    virtual ~Agendador();

    virtual bool agendar(int instante, No* n, Datagrama* d);
    virtual void processar();
    virtual int getInstante();
};

#endif // AGENDADOR_H
