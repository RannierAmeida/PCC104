/**************************************************************
* Autor: Rannier Salles de Almeida
* Data: 13/10/2023
* Mestrando em Ci�ncia da Computa��o
* Universidade Federal de Ouro Preto
* Disciplina: PCC014 - Projeto e An�lise de Algoritmos
* T�pico: Algoritmos de Diminuir e Conquistar
* Descri��o: Implementa��o do algoritmo Binary Search.
**************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// Fun��o de pesquisa bin�ria recursiva
void binarySearch2(vector<int> input, int alvo, int inicio, int fim) {
    // Calcula o �ndice do meio do intervalo
    int meio = (fim - inicio) / 2 + inicio;

    // Exibe informa��es para fins de depura��o
    cout << "\tMeio: " << meio << "\tValor: " << input[meio] << "\tInicio: " << inicio << "\tFim: " << fim << endl;

    if (input[meio] == alvo) {
        cout << endl << "Alvo encontrado"; // O alvo foi encontrado
        return;
    }

    if (input[meio] > alvo) {
        // Se o valor no meio for maior que o alvo, a pesquisa continua na metade esquerda
        binarySearch2(input, alvo, inicio, meio - 1);
    }

    if (input[meio] < alvo) {
        // Se o valor no meio for menor que o alvo, a pesquisa continua na metade direita
        binarySearch2(input, alvo, meio + 1, fim);
    }
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

    // Chama a fun��o de pesquisa bin�ria com os par�metros iniciais
    binarySearch2(input, alvo, 0, n - 1);

    return 0;
}
