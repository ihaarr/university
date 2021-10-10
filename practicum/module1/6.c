#include <stdio.h>

int main() {
    int n, ret;
    ret = 1;
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