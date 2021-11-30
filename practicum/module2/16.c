#include <stdio.h>
#include <stdlib.h>

const int n = 3;

//Найти элемент, который ближе всего к m
int main() {
    int n, m, closeToM, index;

    int arr[n];
    for(int i = 0; i < n; ++i) {
        printf("Enter a element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter number M: ");
    scanf("%d", &m);
    closeToM = arr[0];
    index = 0;
    for(int i = 1; i < n; ++i) {
        if(( abs(abs(m) - abs(arr[i]) )) < abs( (abs(m) - abs(closeToM)) )) {
            closeToM = arr[i];
            index = i;
        }
    }

    printf("el = %d; index = %d\n", closeToM, index);
    return 0; 
}