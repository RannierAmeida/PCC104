// Autor: Rannier Salles de Almeida
// Prova PCC104  - 01
// Algoritmo: SelectionSort

#include <iostream>

void SelectionSort(int A[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }

        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main() {
    int A[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(A) / sizeof(A[0]);
    std::cout << "Size of A: " << n << std::endl;
    SelectionSort(A, n);
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }

    return 0;
}
