#include <stdio.h>

int main() {
    int n, flag;
    flag = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    while(n > 0) {
        if(n % 10 == 9) {
            flag = 1;
            break;
        }

        n /= 10;
    }

    if(flag == 0)
        printf("False\n");
    else
        printf("True\n");

    return 0;
}