#include <stdio.h>

/*
*   Дана квадратная матрица размерности n x n
*/
const int n = 3;

/*
*   Сумма элементов матрица на главной диагонали
*/
void f1(int arr[n][n]) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        result += arr[i][i];
    }

    printf("f1 sum = %d\n", result);
}

/*
*   Сумма элементов матрица на побочной диагонали
*/
void f2(int arr[n][n]) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        result += arr[i][n - 1 - i];
    }

    printf("f2 sum = %d\n", result);
}

/*
*   Сумма элементов матрица выше главной диагонали
*/
void f3(int arr[n][n]) {
    int result = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            result += arr[i][j];
        }
    }

    printf("f3 sum = %d\n", result);
}

/*
*   Сумма элементов матрица ниже главной диагонали
*/
void f4(int arr[n][n]) {
    int result = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            result += arr[i][j];
        }
    }

    printf("f4 sum = %d\n", result);
}

int main() {
    int arr[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    f1(arr);
    f2(arr);
    f3(arr);
    f4(arr);
    return 0;
}