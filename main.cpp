#include "PersistenciaDeRede.h"
#include "Agendador.h"

int main() {
    int opcao = 3;
    int quantidadeDeTempo;
    string nomeDoArquivo;
    int instanteInicial;

    cout << "Nome do arquivo: ";
    cin >> nomeDoArquivo;
    cout << "Instante inicial: ";
    cin >> instanteInicial;
    cout << endl;

    PersistenciaDeRede *p = new PersistenciaDeRede(nomeDoArquivo);
    Rede *retornarda = p->carregar();
    Agendador *ag = new Agendador(instanteInicial, retornarda, 10);


    while (opcao != 0) {
        cout << "Simulador de Rede" << endl;
        cout << "1) Enviar um datagrama" << endl;
        cout << "2) Passar tempo" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {

            list <Hospedeiro*>::iterator h = retornarda->getHospedeiros()->begin();
            cout << endl;

            for (unsigned int i=0; i < retornarda->getHospedeiros()->size(); ++i, ++h) {
                cout << "Hospedeiro: " << (*h)->getEndereco() << endl;
                for (unsigned int j = 0; j < (*h)->getChats()->size(); ++j) {
                    cout << "\tChat: " << (*h)->getChats()->at(j)->getPorta() << endl;
                }
            }

            int enderecoHospedeiro;
            int portaChat;
            string mensagem;
            cout << "Endereco do hospedeiro: ";
            cin >> enderecoHospedeiro;
            cout << "Porta do chat: ";
            cin >> portaChat;
            Hospedeiro *temp = dynamic_cast <Hospedeiro*>(retornarda->getNo(enderecoHospedeiro));
            if ((temp != NULL) && (temp->getChat(portaChat) != NULL)) {
                cout << "Conteudo: " << endl << temp->getChat(portaChat)->getTextoCompleto() << endl;
                cout << "Mensagem: ";
                cin >> mensagem;
                temp->getChat(portaChat)->enviar(mensagem);
                cout << endl;
            } else
                cout << endl <<"Erro: origem desconhecida" << endl << endl;
        }
        if (opcao == 2) {
            cout << endl;
            cout << "Quantidade de tempo: ";
            cin  >> quantidadeDeTempo;
            cout << endl;
            for (int i=0; i < quantidadeDeTempo; ++i) {
               ag->processar();
            }
        }
        if ((opcao != 0) && (opcao != 1) && (opcao != 2)) {
            cout << endl;
        }
    }

    return 0;
}
