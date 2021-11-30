#include <stdio.h>
const int n = 5;

//Определить, сколько элементов массива являются числами фибоначчи, или выдать сообщение, что таких чисел нет
void fill(int arr[n]) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void print(int a[n]) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main() {
    int a[n];
    int count = 0;
    fill(a);
    for(int i = 2; i < n; i++) {
        if(a[i] == a[i - 1] + a[i - 2])
            count++; 
    }

    if(count == 0) printf("NO elements\n");
    else printf("count = %d\n", count);
    return 0;
}