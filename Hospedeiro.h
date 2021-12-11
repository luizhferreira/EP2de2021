#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "RoteadorComQoS.h"
#include "Chat.h"

class Chat;

class Hospedeiro: public No {
    public:
    Hospedeiro(int endereco, Roteador* gateway, int atraso);
    virtual ~Hospedeiro ();

    virtual void adicionarChat(int porta, int enderecoDestino, int portaDestino);
    virtual vector<Chat*>* getChats();
    virtual Chat* getChat(int porta);
    virtual Evento* processar(int instante);
    using No::receber;

    private:
    Roteador* gateway;
    int atraso;
    vector <Chat*>* chats;
};

#endif // HOSPEDEIRO_H
