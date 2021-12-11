#ifndef ROTEADORCOMQOS_H
#define ROTEADORCOMQOS_H

#include "Roteador.h"

class RoteadorComQoS:public Roteador{
    public:
    RoteadorComQoS(int endereco);
    virtual ~RoteadorComQoS();

    virtual void priorizar(int destino);
    virtual vector<int>* getDestinosPriorizados();
    void receber(Datagrama *d);

    private:
    vector <int> *destinosPriorizados;
    FilaComPrioridade *f;
};

#endif // ROTEADORCOMQOS_H
