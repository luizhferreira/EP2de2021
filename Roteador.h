#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "TabelaDeRepasse.h"

#define TAMANHO 10

class Roteador:public No{
    protected:
    Roteador(int endereco, Fila* fila);
    TabelaDeRepasse *tabela;
    int atraso;

    public:
    Roteador(int endereco);
    virtual ~Roteador();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual void setPadrao(No* padrao, int atraso);
    static const int TAMANHO_TABELA = 10;
    virtual Evento* processar(int instante);
    using No::receber;
};

#endif // ROTEADOR_H
