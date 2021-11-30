#include <stdio.h>
#include <stdbool.h>

const int n = 3;
const int m = 3;

//Положить k = 2, если оба массива упорядочены по неубыванию, 1 если только один массив, 0 если не один из них
int main() {
    int A[n], B[m], k;
    bool flag = true;
    k = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    for(int i = 1; i < n; i++) {
        if(!(A[i] >= A[i - 1])) {
            flag = false;
            break;
        }
    }

    if(flag)
        k += 1;

    flag = true;

    for(int i = 1; i < m; i++) {
        if(!(B[i] >= B[i - 1])) {
            flag = false;
            break;
        }
    }

    if(flag)
        k += 1;

    printf("K = %d\n", k);
    return 0;
}