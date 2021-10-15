#include <stdio.h>

/*
*   Дано натуральное число n. Определить, является ли простым числом
*/
int main() {
    int n, count;
    count = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int del = 2; del < n; ++del) {
        if(count != 0)
            break;
        if(n % del == 0)
            ++count;
        ++del;
    }

    if(count == 0)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return 0;
}