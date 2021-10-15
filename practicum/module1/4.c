#include <stdio.h>

/*
* Дана последовательность целых чисел. Определить, является ли макс. элемент четным числом
*/
int main() {
    int n, a, b, max;
    printf("Enter size of seq: ");
    scanf("%d", &n);
    printf("Enter first el: ");
    scanf("%d", &a);
    max = a; //максимальное число
    while(n > 1) {
        printf("Enter next el: ");
        scanf("%d", &b);
        if(b > max) 
            max = b;
        a = b;
        --n;
    }

    if(max % 2 == 0)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return 0;
}