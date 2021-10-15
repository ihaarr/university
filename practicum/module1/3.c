#include <stdio.h>

/*
*   Дано натуральное число n. Если n < 10, то положить M=n!, иначе M=n^k
*   где К подается с ввода
*/
int main() {
    int n, m, M;
    printf("Enter n: ");
    scanf("%d", &n);
    M = 1;
    if(n < 10) 
        while(n > 1)//Кладем факториал
            M *= n;
    else {
        int k;
        printf("Enter k: ");
        scanf("%d", &k);
        for(int i = 0; i <k; ++i) //Кладем n^k
            M *= n;
    }

    printf("M = %d\n", M);
    return 0;
}