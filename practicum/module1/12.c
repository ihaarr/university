#include <stdio.h>

int main() {
    int n, a, b, flag = 1;
    printf("Enter size of seq: ");
    scanf("%d", &n);
    printf("Enter first el: ");
    scanf("%d", &a);
    while(n > 1) {
        printf("Enter next el: ");
        scanf("%d", &b);
        if(b < a) {
            flag = 0;
            break;
        }

        a = b;
        --n;
    }

    if(flag == 0)
        printf("False\n");
    else
        printf("True\n");
    return 0;
}