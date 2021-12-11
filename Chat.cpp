#include "Chat.h"

Chat::Chat(Hospedeiro* h, int porta, int enderecoDestino, int portaDestino){

    if (h == NULL) throw new invalid_argument ("Hospedeiro invalido");

    this->h = h;
    this->porta = porta;
    this->enderecoDestino = enderecoDestino;
    this->portaDestino = portaDestino;

    textoCompleto = ("");
}

Chat::~Chat(){
}

void Chat::enviar(string texto){
    segmento = new Segmento(porta, portaDestino, texto);
    datagrama = new Datagrama(h->getEndereco(), enderecoDestino, segmento);
    h->receber(datagrama);
    textoCompleto += ("\t\tEnviado: ") + texto + ("\n");
}

void Chat::receber(Datagrama *d){
    textoCompleto += ("\t\tRecebido: ") + d->getSegmento()->getDado() + ("\n");
    delete d;
}

string Chat::getTextoCompleto(){
    return textoCompleto;
}

int Chat::getPorta(){
    return porta;
}

void  Chat::imprimir(){
}
