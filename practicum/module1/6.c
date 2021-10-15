#include <stdio.h>

/*
*   Дано натуральное число n. Определить, является ли число степенью числа 2
* 
*/
int main() {
    int n, ret;
    ret = 1;// флаг
    printf("Enter n: ");
    scanf("%d", &n);
    while(n > 1) {
        if(n % 2 != 0) {
            ret = 0;
            break;
        }

        n /= 2;
    }

    if(ret == 1)
        printf("TRUE\n");
    else
        printf("FALSE\n"); 
    return 0;
}