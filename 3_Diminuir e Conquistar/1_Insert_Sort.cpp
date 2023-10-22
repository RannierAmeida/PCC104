#include <iostream>
#include <algorithm>

using namespace std;

void exibeArray(int A[], int n) {
    cout << "Array:\t";
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void insereArray(int A[], int n) {

    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> A[i];
    }
}

void insertionSort(int A[], int n){
   int i,j,temp_j;

    // Percorre todo o vetor a partir da segunda posição
    for(i=1; i < n; i++ ){
        j=i;
        //Ordena indo para tras
        while(j > 0 && A[j-1] > A[j]){
            temp_j = A[j];
            A[j] = A[j-1];
            A[j-1] =temp_j;
            j = j-1;
        }
    }
    exibeArray(A, n);
}

int main() {
    int n;
    cout << "Insira a quantidade de elementos: ";
    cin >> n;

    int A[n];

    insereArray(A, n);

    exibeArray(A, n);

    insertionSort(A,n);

    return 0;
}








