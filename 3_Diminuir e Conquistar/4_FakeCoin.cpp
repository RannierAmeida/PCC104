/**************************************************************
* Autor: Rannier Salles de Almeida
* Data: 13/10/2023
* Mestrando em Ci�ncia da Computa��o
* Universidade Federal de Ouro Preto
* Disciplina: PCC014 - Projeto e An�lise de Algoritmos
* T�pico: Algoritmos de Diminuir e Conquistar
* Descri��o: Implementa��o do algoritmo Binary Search.
* Observacao: Peso da moeda falsa menor
**************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void ImprimeVetor(vector<int> vetor){

    for (int i : vetor) {
        cout << i << " ";
    }
    cout << endl;
}

void verificaMoedas(vector<int> coins) {
    int SomaDireita, SomaEsquerda, tamanho;
    float intervalo_esquerda, intervalo_direita;
    vector<int> BalancaEsquerda;
    vector<int> BalancaDireita;
    vector<int> SemBalanca;

    tamanho = coins.size();
    intervalo_esquerda = (tamanho - tamanho%3)/3;
    intervalo_direita = (tamanho - tamanho%3) * (2.0/3.0) ;
    intervalo_esquerda = floor(intervalo_esquerda);
    intervalo_direita = floor(intervalo_direita);

    if(intervalo_direita <= 2){
        intervalo_direita = 2;
        intervalo_esquerda = 1;

    }

    // Imprime os elementos do vetor 'coins'
    ImprimeVetor(coins);

    cout << endl;

    // Condi��o de Parada 1
    if (tamanho == 1) {
        cout << "Moeda Falsa encontrada, peso: " << coins[0];
        return;
    } else {
        SomaDireita = 0;
        SomaEsquerda = 0;
        // Defini vari�veis
        for (int i = 0; i < tamanho; i++) {
            if (i < intervalo_esquerda) {
                SomaEsquerda = SomaEsquerda + coins[i];
                BalancaEsquerda.push_back(coins[i]);
            } else if (i >= intervalo_esquerda && i < intervalo_direita)  {
                SomaDireita = SomaDireita + coins[i];
                BalancaDireita.push_back(coins[i]);
            } else {
                SemBalanca.push_back(coins[i]);
            }
        }

        //Imprime valors atuais
        cout << "Tamanho vetor: " << tamanho << " "<<  intervalo_esquerda << " "<< intervalo_direita << "\tSoma Esquerda: " << SomaEsquerda << "\tSoma Direita: " << SomaDireita << endl << endl;
        cout << "Balanca Esquerda: ";
        ImprimeVetor(BalancaEsquerda);
        cout << "Balan�a Direita: " ;
        ImprimeVetor(BalancaDireita);
        cout << "Sem balan�a: ";
        ImprimeVetor(SemBalanca);

        // Compara��es
        if (SomaDireita > SomaEsquerda) {
            verificaMoedas(BalancaEsquerda);
        } else if (SomaDireita < SomaEsquerda) {
            verificaMoedas(BalancaDireita);
        } else {
            verificaMoedas(SemBalanca);
        }
    }
}

int main() {
    vector<int> coins;
    int n;
    int tempCoin;

    cout << "Insira o n�mero de moedas: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Insira o peso da moeda: ";
        cin >> tempCoin;
        coins.push_back(tempCoin);
    }


    verificaMoedas(coins);
    return 0;
}
