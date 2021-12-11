#include "PersistenciaDeRede.h"

PersistenciaDeRede::PersistenciaDeRede(string arquivo): nomeDoArquivo(arquivo){
}

PersistenciaDeRede::~PersistenciaDeRede(){
}

Rede* PersistenciaDeRede::carregar(){
    Rede *criada = new Rede();
    Hospedeiro *h;
    RoteadorComQoS *rQoS;

    int enderecoMapear, roteadorPadrao, atrasoPadrao, quantidadeMapear, noFor, enderecoFor, atrasoFor;
    Roteador *auxiliar;
    No *padrao;

    ifstream leitura;
    leitura.open(nomeDoArquivo);

    if (leitura.fail()) {
        leitura.close();
        throw new logic_error ("Problema de leitura");
    }

    int quantidadeDeRoteadores;
    leitura >> quantidadeDeRoteadores;
    string indicador;
    leitura >> indicador;

    while (indicador == "r" || indicador == "q") {
        if (indicador == "r") {
            int endereco;
            leitura >> endereco;
            criada->adicionar(new Roteador(endereco));
        }
        leitura >> indicador;
        if (indicador == "q") { // caso onde estou lendo um RoteadorComQoS
            int enderecoQoS, quantidadePriorizados, numero;
            leitura >> enderecoQoS;
            rQoS = new RoteadorComQoS(enderecoQoS);
            leitura >> quantidadePriorizados;
            for (int j=0; j < quantidadePriorizados; ++j){
                leitura >> numero;
                rQoS->priorizar(numero);
            }
            criada->adicionar(rQoS);
            leitura >> indicador;
        }
    }
    //parte dos hospedeiros
    stringstream container (indicador);
    int quantidadeDeHospedeiros;
    container >> quantidadeDeHospedeiros;
    //int quantidadeDeHospedeiros = stoi(indicador);
    for (int k = 0; k < quantidadeDeHospedeiros; ++k) {
        int hospedeiroEndereco, gateway, atraso, quantidadeDeChats, porta, enderecoDoDestino, portaDeDestino;
        leitura >> hospedeiroEndereco;
        leitura >> gateway;
        leitura >> atraso;
        h = new Hospedeiro(hospedeiroEndereco, new RoteadorComQoS(gateway), atraso);
        leitura >> quantidadeDeChats;
        for (int f = 0; f < quantidadeDeChats; ++f) {
            leitura >> porta;
            leitura >> enderecoDoDestino;
            leitura >> portaDeDestino;
            h->adicionarChat(porta, enderecoDoDestino, portaDeDestino);
        }
        criada->adicionar(h);
    }

    for (int t = 0; t < quantidadeDeRoteadores; ++t) {
        leitura >> enderecoMapear;
        auxiliar = dynamic_cast <Roteador*>(criada->getNo(enderecoMapear));
        leitura >> roteadorPadrao;
        leitura >> atrasoPadrao;
        padrao = criada->getNo(roteadorPadrao);
        auxiliar->setPadrao(padrao, atrasoPadrao);
        leitura >> quantidadeMapear;
        for (int m = 0; m < quantidadeMapear; ++m) {
            leitura >> enderecoFor;
            leitura >> noFor;
            leitura >> atrasoFor;
            auxiliar->mapear(enderecoFor, criada->getNo(noFor), atrasoFor);
        }
    }
    leitura.close();
    return criada;
}
