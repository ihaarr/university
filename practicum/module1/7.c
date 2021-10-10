#include <stdio.h>

int main() {
    int n, a, b, min;
    printf("Enter size of seq: ");
    scanf("%d", &n);
    printf("Enter first el: ");
    scanf("%d", &a);
    min = a;
    int i = 1;
    int index = 1;
    while(n > 1) {
        printf("Enter next el: ");
        scanf("%d", &b);
        ++i;
        if(b < min) {
            min = b;
            index = i;
        }

        --n;
    }

    printf("index = %d\n min = %d\n", index, min);
    return 0;
}