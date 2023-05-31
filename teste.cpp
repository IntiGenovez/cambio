#include "lib.h"


using namespace std;

int main() {
    // Lista de moedas
    string moedas[] = {"Bolivar Soberano venezuelano", "Boliviano boliviano", "Guarani paraguaio", "Peso argentino", "Peso uruguaio", "Real brasileiro"};

    // Taxas de câmbio
    float taxas[] = {5.16, 1.36, 1435.89 , 47.31, 7.66, 1}, resultado;

    exibirParticipantes();

    TransacaoCambio transacao = obterMoedas(moedas, taxas);

    resultado = cambiar(transacao.moeda_origem, transacao.moeda_destino, transacao.quantidade, taxas);

    exibirResultado(transacao, resultado, moedas);

    return 0;
}
