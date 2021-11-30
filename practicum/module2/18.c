#include <stdio.h>
#include <stdlib.h>

const int n = 3;

//Написать программу транспонирования матрицы
// a) Результат в другую матрицу
// b) Результат на место исходной
int** a(int matrix[n][n]) {
    int** matrixNew = (int**) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        matrixNew[i] = (int) malloc(sizeof(int));
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            matrixNew[j][i] = matrix[i][j]; 
        }
    }

    return matrixNew;
}

void b(int matrix[n][n]) {
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j]; 
            matrix[i][j] = temp;
        }
    }
}

void print(int matrix[n][n]) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int arr[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("Enter a el with indexes i = %d j = %d: ", i + 1, j + 1);
            scanf("%d",&arr[i][j]);
        }
    }

    //print(a(arr, n), n);
    b(arr);
    print(arr);
    return 0;
}