#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

class TransacaoCambio {
    public:
        TransacaoCambio(int moeda_origem, int moeda_destino, float quantidade) {
            this->moeda_origem = moeda_origem;
            this->moeda_destino = moeda_destino;
            this->quantidade = quantidade;
        }
        int moeda_origem, moeda_destino;
        float quantidade;
};

void exibirParticipantes() {
    system("cls");
    // Título e nomes dos desenvolvedores
    cout << "Conversor de Moedas do Mercosul\n";
    cout << "Bruno Araujo\nFelipe Soares\nGuilherme Balbo\nGustavo Nascimento\nHebert Ruan\nInti Genovez\nJoão Victor Lucio\nLeandro Robatino\nLeticia Akemi\nLucas Guilherme\nRafael Ricardo\nVinicius Valerini\n\n";
    system("pause");
    system("cls");
}

TransacaoCambio obterMoedas(string moedas[], float taxas[]) {
    // Escolha das moedas
    int moeda_origem, moeda_destino;
    float quantidade;

    do {

        cout << "Selecione a moeda de origem:\n";
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << ". " << moedas[i] << endl;
        }
        cin >> moeda_origem;

        if (moeda_origem < 1 || moeda_origem > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "Opcao invalida\n\n";
        }
        system("cls");
    } while (moeda_origem > 6 || moeda_origem < 1) ;

    do {
        cout << "Selecione a moeda de destino:\n";
        for (int i = 0; i < 6; i++) {
            if (i != moeda_origem - 1) {
                cout << i + 1 << ". " << moedas[i] << endl;
            }
        }
        cin >> moeda_destino;
        if (moeda_destino < 1 || moeda_destino > 6 || moeda_destino == moeda_origem) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "Opcao invalida\n\n";
        }
    } while (moeda_destino > 6 || moeda_destino < 1 || moeda_destino == moeda_origem);

    // Conversão de moeda
    cout << "Quantidade: ";
    cin >> quantidade;

    TransacaoCambio transacao(moeda_origem, moeda_destino, quantidade);
    return transacao;
}

float cambiar(int moeda_origem, int moeda_destino, float quantidade, float taxas[]) {
    float valor_convertido = quantidade * taxas[moeda_destino - 1] / taxas[moeda_origem - 1];
    return valor_convertido;
}

void exibirResultado(TransacaoCambio transacao, float valor_convertido, string moedas[]) {
    // Exibição do resultado
    cout << "R$" << transacao.quantidade << " " << moedas[transacao.moeda_origem - 1] << " = R$" << valor_convertido << " " << moedas[transacao.moeda_destino - 1] << endl;
}