#include "Hospedeiro.h"

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway, int atraso):
    No(endereco), gateway(gateway), atraso(atraso), chats(new vector <Chat*>()){
}

Hospedeiro::~Hospedeiro(){
    for (unsigned int i = 0; i < chats->size();)  delete chats->at(i++);
    delete chats;
}

Evento*Hospedeiro::processar(int instante){
    if (fila->isEmpty()) return NULL;

    cout << "Hospedeiro: " << endereco << endl;
    Datagrama *removido = fila->dequeue();
    if (removido->getDestino() == endereco) {
        if (getChat(removido->getSegmento()->getPortaDeDestino()) != NULL) {
            cout << "\tMensagem recebida" << endl;
            Chat *k = getChat(removido->getSegmento()->getPortaDeDestino());
            k->receber(removido);
            cout << k->getTextoCompleto();// << endl;
        } else {
            cout << "\tSem chat: Origem: " << removido->getOrigem() << ":"
            << removido->getSegmento()->getPortaDeOrigem() << ", Destino: "
            << removido->getDestino() << ":" << removido->getSegmento()->getPortaDeDestino()
            << ", " << removido->getSegmento()->getDado();// << endl;
            delete removido;
        }
        return NULL;
    } else {
        cout << "\tMensagem enviada"<< endl;
        Evento *e = new Evento((instante + atraso), gateway, removido);
        return e;
    }
}

void Hospedeiro::adicionarChat(int porta, int enderecoDestino, int portaDestino){
    if (getChat(porta) == NULL) {
        Chat *c = new Chat(this, porta, enderecoDestino, portaDestino);
        chats->push_back(c);
    } else
        throw new logic_error ("Porta ja adicionada");
}

Chat*Hospedeiro::getChat(int porta){
    if (!chats->empty()) {
        for (unsigned int i = 0;  i < chats->size(); ++i) {
            if (chats->at(i)->getPorta() == porta) {
                return chats->at(i);
            }
        }
    }
    return NULL;
}

vector<Chat*>*Hospedeiro::getChats(){
    return chats;
}
