#include "Roteador.h"

Roteador::Roteador(int endereco):
    No(endereco), tabela(new TabelaDeRepasse(TAMANHO_TABELA)){
}

Roteador::Roteador(int endereco, Fila* fila):
    No(endereco, fila), tabela(new TabelaDeRepasse(TAMANHO_TABELA)){
}

Roteador::~Roteador(){
    delete tabela;
}

void Roteador::mapear(int endereco, No* adjacente, int atraso){
    tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(No* padrao, int atraso){
    tabela->setPadrao(padrao, atraso);
}

Evento* Roteador::processar(int instante){
    if (fila -> isEmpty()) return NULL;

    cout << "Roteador: " << getEndereco() << endl;

    Datagrama *auxiliar = fila -> dequeue();
    if (auxiliar->getDestino() == endereco) {
        cout << "\tRecebido: " << auxiliar->getSegmento() << endl;
        delete auxiliar;
        return NULL;
    }

    No *ajudante = tabela->getProximoSalto(auxiliar->getDestino(), atraso);
    if (ajudante == NULL) {
        cout << "\tSem proximo: Origem: " << auxiliar->getOrigem()
             << ", Destino: " << auxiliar->getDestino()
             << ", " << auxiliar->getSegmento() << endl;
        delete auxiliar;
        return NULL;
    }

    Evento *E = new Evento(instante + atraso, ajudante, auxiliar);
    cout << "\tRepassado para " << E->getDestino()->getEndereco() << " (Instante " << instante + atraso
         << "): Origem: " << auxiliar->getOrigem() << ":"
            << E->getDatagrama()->getSegmento()->getPortaDeOrigem() << ", Destino: "
            << auxiliar->getDestino() << ":" << auxiliar->getSegmento()->getPortaDeDestino()
            << ", " << auxiliar->getSegmento()->getDado() << endl;

    return E;
}
