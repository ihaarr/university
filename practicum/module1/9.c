#include <stdio.h>

/*
*   Дано натуральное число n. Определить, есть ли хотя бы одна цифра 9 в записи числа
*/
int main() {
    int n, cn, flag;
    flag = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    cn = n;
    while(cn > 0) {
        if(cn % 10 == 9) {
            flag = 1;
            break;
        }

        cn /= 10;
    }

    if(flag == 0)
        printf("False\n");
    else
        printf("True\n");

    return 0;
}