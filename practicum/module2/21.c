#include <stdio.h>

//Найти скалярное произведение строки на столбец, на пересечении которых находится последний минимальный элемент матрицы
const int n = 3;
int main() {
    int minJ, minI;
    float arr[n][n];
    float min, result;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%f", &arr[i][j]);
        }
    }

    result = 0;
    min = arr[0][0];
    minJ = 0;
    minI = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(min > arr[i][j]) {
                min = arr[i][j];
                minJ = j;
                minI = i;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        result += arr[minI][i] * arr[i][minJ];
    }

    printf("RESULT = %f\n", result);
    return 0;
}