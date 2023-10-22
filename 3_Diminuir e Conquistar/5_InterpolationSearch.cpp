/**************************************************************
* Autor: Rannier Salles de Almeida
* Data: 13/10/2023
* Mestrando em Ciência da Computação
* Universidade Federal de Ouro Preto
* Disciplina: PCC014 - Projeto e Análise de Algoritmos
* Tópico: Algoritmos de Diminuir e Conquistar
* Descrição: Implementação do algoritmo Interpolation Search.
**************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// Função de pesquisa por interpolação
void interpolationSearch(vector<int> input, int alvo) {
    int inicio = 0;
    int fim = input.size() - 1;

    while (inicio <= fim && alvo >= input[inicio] && alvo <= input[fim]) {
        int posicao = inicio + ((double)(fim - inicio) / (input[fim] - input[inicio])) * (alvo - input[inicio]);

        // Exibe informações para fins de depuração
        cout << "Tentativa: " << posicao << "\tValor: " << input[posicao] << endl;

        if (input[posicao] == alvo) {
            cout << endl << "Alvo encontrado"; // O alvo foi encontrado
            return;
        }

        if (input[posicao] < alvo) {
            inicio = posicao + 1;
        } else {
            fim = posicao - 1;
        }
    }

    cout << endl << "Alvo não encontrado";
}

int main() {
    vector<int> input;
    int intTemp;
    int n;
    int alvo;

    cout << "Insira o alvo: ";
    cin >> alvo;
    cout << "Insira o número de elementos: ";
    cin >> n;
    cout << "Insira os elementos: ";

    for (int i = 0; i < n; i++) {
        cin >> intTemp;
        input.push_back(intTemp);
    }

    // Imprime os elementos do vetor
    for (int i : input) {
        cout << i << " ";
    }
    cout << endl << endl;

    // Chama a função de pesquisa por interpolação
    interpolationSearch(input, alvo);

    return 0;
}
