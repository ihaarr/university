#include <stdio.h>

int main() {
    int n, del, cn, count;
    count = 0;
    del = 2;
    printf("Enter n: ");
    scanf("%d", &n);
    while(del < n) {
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