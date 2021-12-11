#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    if (tamanho <= 0) {
        throw new invalid_argument("Tamanho invalido");
    }

    this->tamanho = tamanho;
    quantidadeDeAdjacentes = 0;

    vetorAdjacentes = new No*[tamanho];
    vetorAtrasos = new int(tamanho);
    vetorEnderecos = new int(tamanho);

    setPadrao(NULL, 0);
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] vetorAdjacentes;
    delete[] vetorAtrasos;
    delete[] vetorEnderecos;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente, int atraso){
    if (quantidadeDeAdjacentes == tamanho)
        throw new overflow_error("A tabela de repasse esta cheia");

    if (quantidadeDeAdjacentes > 0) {
        for (int i = 0; i < quantidadeDeAdjacentes; ++i) {
            if (vetorEnderecos[i] == endereco) {
                throw new invalid_argument("No ja adicionado");
            }
        }
    }

    vetorAtrasos[quantidadeDeAdjacentes] = atraso;
    vetorEnderecos[quantidadeDeAdjacentes] = endereco;
    vetorAdjacentes[quantidadeDeAdjacentes++] = adjacente;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return quantidadeDeAdjacentes;
}

No**TabelaDeRepasse:: getAdjacentes(){
    return vetorAdjacentes;
}

void TabelaDeRepasse::setPadrao(No* padrao, int atraso){
    this->padrao = padrao;
    atrasoDoPadrao = atraso;
}

No*TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    for (int p=0; p < getQuantidadeDeAdjacentes(); ++p) {
        if (endereco==vetorEnderecos[p]) {
            atraso = vetorAtrasos[p];
            return vetorAdjacentes[p];
        }
    }
    atraso = atrasoDoPadrao;
    return padrao;
}

void TabelaDeRepasse::imprimir(){
   /*  cout << endl
         << "Tabela de Repasse " << endl
         << "Tamanho: " << tamanho << endl
         << "Padrao-> "; padrao->imprimir();
    cout << "Adjacentes-> " << endl;
         for (int i=0; i<quantidadeDeAdjacentes;) vetorAdjacentes[i++]->imprimir();
    cout << "Endereços: "; for (int i=0; i<quantidadeDeAdjacentes;) cout << vetorEnderecos[i++] << " "; cout << endl;
    cout << "Atrasos: "; for (int i=0; i<quantidadeDeAdjacentes;) cout << vetorAtrasos[i++] << " "; cout << endl; */
}
