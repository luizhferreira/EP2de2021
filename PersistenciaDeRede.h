#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include "Rede.h"
#include <fstream>
#include <sstream>

class PersistenciaDeRede {
    public:
    PersistenciaDeRede(string arquivo);
    virtual ~PersistenciaDeRede();

    virtual Rede* carregar();

    private:
    ofstream doc;
    string nomeDoArquivo;
};

#endif // PERSISTENCIADEREDE_H
