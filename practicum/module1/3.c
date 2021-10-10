#include <stdio.h>

int main() {
    int n, m, M;
    printf("Enter n: ");
    scanf("%d", &n);
    M = 1;
    if(n < 10)
        while(n > 1)
            M *= n;
    else {
        int k;
        printf("Enter k: ");
        scanf("%d", &k);
        for(int i = 0; i <k; ++i)
            M *= n;
    }

    printf("M = %d\n", M);
    return 0;
}