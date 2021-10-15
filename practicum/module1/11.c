#include <stdio.h>

/*
*   Дан целочисленный массив, состоящий из n элементов. Разменять местами максимальный и минимальный элемент. 
*/
int main() {
    int n, indexMin, min, indexMax, max;
    printf("Enter a size of array: ");
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; ++i) {
        printf("Enter el: ");
        scanf("%d", &arr[i]);
    }

    min = arr[0];
    max = arr[0];
    indexMin = 0;
    indexMax = 0;
    for(int i = 1; i < n; ++i) {
        if(min > arr[i]) {
            min = arr[i];
            indexMin = i;
        } else if (max < arr[i]) {
            max = arr[i];
            indexMax = i;
        }
    }

    //Меняем местами значения
    arr[indexMin] += arr[indexMax];
    arr[indexMax] = arr[indexMin] - arr[indexMax];
    arr[indexMin] -= arr[indexMax];

    for(int i = 0; i < n; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}