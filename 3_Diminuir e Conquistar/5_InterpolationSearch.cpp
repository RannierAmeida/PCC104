/**************************************************************
* Autor: Rannier Salles de Almeida
* Data: 13/10/2023
* Mestrando em Ci�ncia da Computa��o
* Universidade Federal de Ouro Preto
* Disciplina: PCC014 - Projeto e An�lise de Algoritmos
* T�pico: Algoritmos de Diminuir e Conquistar
* Descri��o: Implementa��o do algoritmo Interpolation Search.
**************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// Fun��o de pesquisa por interpola��o
void interpolationSearch(vector<int> input, int alvo) {
    int inicio = 0;
    int fim = input.size() - 1;

    while (inicio <= fim && alvo >= input[inicio] && alvo <= input[fim]) {
        int posicao = inicio + ((double)(fim - inicio) / (input[fim] - input[inicio])) * (alvo - input[inicio]);

        // Exibe informa��es para fins de depura��o
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

    cout << endl << "Alvo n�o encontrado";
}

int main() {
    vector<int> input;
    int intTemp;
    int n;
    int alvo;

    cout << "Insira o alvo: ";
    cin >> alvo;
    cout << "Insira o n�mero de elementos: ";
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

    // Chama a fun��o de pesquisa por interpola��o
    interpolationSearch(input, alvo);

    return 0;
}
