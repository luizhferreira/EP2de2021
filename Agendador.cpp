#include "Agendador.h"

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho):
    instanteInicial(instanteInicial), rede(rede), tamanho(tamanho){

    eventosAgendados = new Evento*[tamanho];

    ordemAgendamento = new int[tamanho];
    agendamentos=0;
    elementosAgendados = 0;
    inicio = 0;
    fim = 0;
}

Agendador::~Agendador(){
    for (int i=0; i < elementosAgendados;) delete eventosAgendados[i++];
    delete[] eventosAgendados;
}

int Agendador::particao(Evento** &A, int* &O, int in, int f){
    Evento *e_pivo = A[f];
    int o_pivo = O[f];
    int pmaior = in;
    for (int p=in; p<f; ++p) {
        if (A[p]->getInstante() > e_pivo->getInstante() || (A[p]->getInstante() == e_pivo->getInstante() && O[p] > O[f])) {
            Evento *temp = A[p];
            int tempO = O[p];
            A[p] = A[pmaior], A[pmaior] = temp;
            O[p] = O[pmaior], O[pmaior] = tempO;
            ++pmaior;
        }
    }
    A[f] = A[pmaior], A[pmaior] = e_pivo;
    O[f] = O[pmaior], O[pmaior] = o_pivo;
    return (pmaior);
}

void Agendador::quickSort (Evento** &A, int*&O ,int in, int f){
    if (in<f) {
        int pivo=particao(A, O, in, f);
        quickSort(A, O, in, pivo-1);
        quickSort(A, O, pivo+1, f);
    }
}

bool Agendador::agendar(int instante, No* n, Datagrama* d){
    if (elementosAgendados == tamanho)
        return false;

    Evento *K = new Evento(instante, n, d);
    enqueue(K);
        return true;
}

void Agendador::processar(){
    //primeiro faço qsort
    quickSort(eventosAgendados, ordemAgendamento, 0, elementosAgendados-1);
    inicio=elementosAgendados-1, fim=elementosAgendados;

    //Pra que serve esse for? ele objetiva processar todos os eventos no meu vetor eventosAgendados programados
    //para esse momento.
    for (int i = inicio; i >= 0; --i) {
        if (eventosAgendados[i]->getInstante() == instanteInicial) {
                //quando o if acima encontrar um evento com o mesmo instante de agora, ele ira executar o codigo abaixo:
                //isso quer dizer que eu vou pegar o cara que ta na posição i do meu vetor e mandar para ele o datagrama
                //que estava agendado
        //eventosAgendados[i] -> getDestino() -> getDestinosPriorizados();
             No *h = rede->getNo(eventosAgendados[i]->getDestino()->getEndereco());
             h->receber(eventosAgendados[i]->getDatagrama());
        //e agora? bem, esse evento ja foi efetivado. portanto precisamos liberar espaço no vetor atraves desse dequeue:
            dequeue();
        }
    }

    cout << "Instante: " << instanteInicial << endl
         << "---" << endl;
    list <No*>::iterator i = rede -> getNos()-> begin();
    while (i != rede->getNos()->end()) {
        Evento *T = (*i)->processar(instanteInicial);
        if (T != NULL && elementosAgendados < tamanho){
            enqueue(T);
        }
        ++i;
    }
    cout << endl;
    ++instanteInicial;
}

void Agendador::enqueue(Evento *e){
     if (elementosAgendados < tamanho) {
        ordemAgendamento[fim]=++agendamentos;
        eventosAgendados[fim++] = e;
        ++elementosAgendados;
        if (fim == tamanho) fim = 0;
    }
}

void Agendador::dequeue(){
    if (elementosAgendados > 0) {
        delete eventosAgendados[inicio];
        ordemAgendamento[inicio]=0;
        eventosAgendados[inicio--]=NULL;
        --fim;
        --elementosAgendados;
        if (inicio<0) inicio = 0;
    }
}

int Agendador::getInstante(){
    return instanteInicial;
}
