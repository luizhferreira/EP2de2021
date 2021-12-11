#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "Evento.h"
#include "No.h"

class TabelaDeRepasse {
    private:
    int tamanho;

    No *adjacente;
    int quantidadeDeAdjacentes;

    No *padrao;
    int atrasoDoPadrao;

    //Vetores criados
    int *vetorEnderecos;
    No **vetorAdjacentes;
    int *vetorAtrasos;

    public:
    TabelaDeRepasse(int tamanho);
    virtual ~TabelaDeRepasse();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual No** getAdjacentes();
    virtual int getQuantidadeDeAdjacentes();
    virtual void setPadrao(No* padrao, int atraso);
    virtual No* getProximoSalto(int endereco, int& atraso);

    virtual void imprimir();
};

#endif // TABELADEREPASSE_H
