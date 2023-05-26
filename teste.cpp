#include "lib.h"


using namespace std;

int main() {
    // Lista de moedas
    string moedas[] = {"Bolivar Soberano venezuelano", "Boliviano boliviano", "Guarani paraguaio", "Peso argentino", "Peso uruguaio", "Real brasileiro"};

    // Taxas de câmbio
    float taxas[] = {0.000023, 0.142, 0.00015, 0.010, 0.023, 0.18}, resultado;

    exibirParticipantes();

    TransacaoCambio transacao = obterMoedas(moedas, taxas);

    resultado = cambiar(transacao.moeda_origem, transacao.moeda_destino, transacao.quantidade, taxas);

    exibirResultado(transacao, resultado, moedas);

    return 0;
}