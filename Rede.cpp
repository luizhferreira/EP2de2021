#include "Rede.h"

Rede::Rede(): no(new list <No*>()){
}

Rede::~Rede(){
    while (!no->empty()) {
    No *ultimo = no->back();
    no->pop_back();
    delete ultimo;
    }
    delete no;
}

void Rede::adicionar(No* n){
    if (getNo(n->getEndereco()) == NULL)
        no->push_back(n);
    else
        throw new logic_error("No ja adicionado");
}

list <No*>*Rede::getNos(){
    return no;
}

list<Hospedeiro*>*Rede::getHospedeiros(){
    list <Hospedeiro*>* hospedeiros = new list <Hospedeiro*>();
    list <No*>::iterator i = no->begin();
    while (i != no->end()) {
        Hospedeiro *H = dynamic_cast <Hospedeiro*>(*(i++));
        if (H != NULL) {
            hospedeiros->push_back(H);
        }
    }
    return hospedeiros;
}

No*Rede::getNo(int endereco){
    list <No*>::iterator i = no->begin();
    while (i != no->end()) {
        if ((*i)->getEndereco() == endereco) {
            return (*i);
        }
        ++i;
    }
    return NULL;
}

void Rede::imprimir(){
  /*  cout << "O vetor roteadores esta assim: " << endl;
    for(int i=0; i<quantidadeDeRoteadores;) cout << roteadores[i++]-> getEndereco() << " "; */
}
