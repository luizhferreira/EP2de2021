#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, Segmento* dado):
    origem(origem), destino(destino), dado(dado){
}

Datagrama::~Datagrama(){
    delete dado;
}

Segmento*Datagrama::getSegmento(){
    return dado;
}

int Datagrama::getDestino(){
    return destino;
}

int Datagrama::getOrigem(){
    return origem;
}

void Datagrama::imprimir(){
    cout << "Mensagem: " << getSegmento() << endl;
}
