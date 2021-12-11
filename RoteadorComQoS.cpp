#include "RoteadorComQoS.h"

RoteadorComQoS::RoteadorComQoS(int endereco):
    Roteador(endereco, f = new FilaComPrioridade(TAMANHO_FILA)), destinosPriorizados(new vector<int>()){
}

RoteadorComQoS::~RoteadorComQoS(){
    delete destinosPriorizados;
}

void RoteadorComQoS::priorizar(int destino){
    destinosPriorizados->push_back(destino);
}

vector <int> *RoteadorComQoS::getDestinosPriorizados(){
    return destinosPriorizados;
}

void RoteadorComQoS::receber(Datagrama *d){
    if (f->getSize() >= TAMANHO_FILA)
        cout << "\tFila em " << getEndereco() << " estourou" << endl;

    bool teste = false;

    if (!destinosPriorizados->empty()) {
        for (unsigned int i = 0; i < destinosPriorizados->size(); ++i) {
            if (destinosPriorizados->at(i) == d->getDestino()) {
                f->enqueue(d, true);
                teste = true;
            }
        }
    }

    if (teste==false)
        f->enqueue(d, false);
}
