#include <stdio.h>
#include <stdbool.h>

const int n = 2;
const int m = 2;

//Построить матрицу C, где C[i][j] равен сумме элементов i-й строки А, которые отсуствуют в j-ом столбце B
bool isExistEl(float element, int column, float b[n][m]) {
    bool isExist = false;
    for(int i = 0; i < n; i++) {
            if(b[i][column] == element) {
                isExist = true;
                break;
            }
    }
    return isExist;
}

void fill(float arr[n][m]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%f", &arr[i][j]);
        }
    }
}

float sumElementsNotExist(int i, int j, float a[n][m], float b[n][m]) {
    float sum = 0;
    for(int k = 0; k < n; k++) {
        if(!isExistEl(a[i][k], j, b)) {
            sum += a[i][k];
        }
    }

    return sum;
}

void print(float a[n][m]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%f ", a[i][j]);
        }

        printf("\n");
    }
}

int main() {
    float a[n][m], b[n][m], c[n][m];
    printf("Enter first matrix: \n");
    fill(a);
    printf("Enter second matrix: \n");
    fill(b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            c[i][j] = sumElementsNotExist(i, j, a, b);
        }
    }

    print(c);
    return 0;
}