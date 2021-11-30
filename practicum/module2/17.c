#include <stdio.h>
#include <limits.h>

const int n = 3;
const int m = 3;

//Найти строку с наименьшей суммой элементов
int main() {
    int sumMin, index;

    int arr[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("Enter a el with indexes i = %d j = %d: ", i + 1, j + 1);
            scanf("%d",&arr[i][j]);
        }
    }

    sumMin = INT_MAX;
    index = -1;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < m; ++j) {
            sum += arr[i][j];
        }

        if(sum < sumMin) {
            index = i;
            sumMin = sum;
        }
    }

    printf("sum = %d; line = %d\n", sumMin, index + 1);
    return 0;
}