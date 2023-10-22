// Autor: Rannier Salles de Almeida
// Prova PCC104  - 01
// Algoritmo: Busca em Largura e Profundidade
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> InseriMatriz(int No) {
    vector<vector<int>> AdjMatriz(No, vector<int>(No));

    for (int i = 0; i < No; i++) {
        for (int j = 0; j < No; j++) {
            cout << "A" << i << j << ": ";
            cin >> AdjMatriz[i][j];
        }
    }

    return AdjMatriz;
}

void ImprimeMatriz(vector<vector<int>> AdjMatriz, int No) {
    cout << endl << "Matriz de Adjacencia:" << endl;

    for (int i = 0; i < No; i++) {
        for (int j = 0; j < No; j++) {
            if (j != No - 1)
                cout << AdjMatriz[i][j] << "\t";
            else
                cout << AdjMatriz[i][j] << endl;
        }
    }
}

void MostrarPilha(stack<int> pilha) {
    cout << endl;
    cout << "Elementos da Pilha:";
    while (!pilha.empty()) {
        cout << pilha.top() << " ";
        pilha.pop();
    }

}

void MostrarFila(queue<int> fila) {
    cout << endl;
    cout << "Elementos da Fila:";
    while (!fila.empty()) {
        cout << fila.front() << " ";
        fila.pop();
    }
}


void BuscaProfundidade(vector<vector<int>>& AdjMatriz, int No, int Inicial[2], int alvo) {
    vector<bool> visitados(No, false);
    stack<int> pilha;
    int inicio = Inicial[0];

    cout << "Busca em Profundidade a partir do No " << inicio << " para o alvo " << alvo << ": ";

    pilha.push(inicio);


    while (!pilha.empty()) {
        int NoAtual = pilha.top();
        cout << "No atual: "<< NoAtual;

        pilha.pop();


        if (!visitados[NoAtual]) {
            cout << NoAtual<< " ";
            visitados[NoAtual] = true;

            if (NoAtual == alvo) {
                cout << "Alvo encontrado!" << endl;
                cout << endl;
                cout << endl;
                return;
            }

            for (int i = 0; i < No; i++) {
                if (AdjMatriz[NoAtual][i] && !visitados[i] && NoAtual != i) {
                    pilha.push(i);
                }
            }
        }
    }

    cout << "Alvo não encontrado." << endl;
    cout << endl;
    cout << endl;
}

void Primeiro_No(const vector<vector<int>>& AdjMatriz, int No, int inicial[2]) {
    for (int i = 0; i < No; i++) {
        for (int j = 0; j < No; j++) {
            if (AdjMatriz[i][j] != 0) {
                cout << endl << "No Inicial: A" << i << j << endl;
                inicial[0] = i;
                inicial[1] = j;
                return;
            }
        }
    }
}

void BuscaLargura(vector<vector<int>> AdjMatriz, int No, int Inicial[2], int alvo) {
    queue<int> q;
    vector<bool> visitados(No, false);

    int inicio = Inicial[0]; // O primeiro elemento de Inicial é o vértice de início
    cout << "Busca em Largura a partir do No " << inicio << " para o alvo " << alvo << ": ";

    q.push(inicio);
    visitados[inicio] = true;

    while (!q.empty()) {
        int NoAtual = q.front();
        q.pop();


        cout << NoAtual<< " ";

        if (NoAtual == alvo) {
            cout << "Alvo encontrado!" << endl;
            cout << endl;
            cout << endl;
            return;
        }

        for (int i = 0; i < No; i++) {
            if (AdjMatriz[NoAtual][i] && !visitados[i]) {
                q.push(i);
                visitados[i] = true;
            }
        }
    }

    cout << "Alvo não encontrado." << endl;
    cout << endl;
    cout << endl;
}

int main() {
    int No;
    int Inicial[2];
    int alvo;

    cout << "Entre com a quantidade de nos: ";
    cin >> No;

    cout << "Insira os valores da matriz Aij" << endl;
    vector<vector<int>> AdjMatriz = InseriMatriz(No);
    ImprimeMatriz(AdjMatriz, No);

    Primeiro_No(AdjMatriz, No, Inicial);

    cout << "Entre com o no alvo: ";
    cin >> alvo;

    BuscaLargura(AdjMatriz, No, Inicial, alvo);
    BuscaProfundidade(AdjMatriz, No, Inicial, alvo);

    return 0;
}
