// Autor: Rannier Salles de Almeida
// Prova PCC104  - 01
// Algoritmo: SequentialSearch2

#include <iostream>

int SequentialSearch2(int A[], int n,int K) {

    int i = 0;

   do{
    i = i+1;
   } while (A[i] != K);

    if (i < n)
        {return i;}
    else
        {return -1;}
}

int main() {
    int Answer;
    int K;
    int A[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(A) / sizeof(A[0]);
    std::cout << "Insira valor procurarado:";
    std::cin >> K;
    std::cout << "Size of A: " << n << std::endl;
    Answer = SequentialSearch2(A, n,K );
    if (Answer >= 0)
        {
        std::cout << "Posicao: " << Answer;
        }
    else
        {
        std::cout << "Elemento nao encontrado";
        }
    return 0;
}
