#include <iostream>

const int n = 1;
int main() {
    int max, f1, f2;
    f1 = 1;
    f2 = 1;
    max = 1;
    while(max < n) {
        max = f1 + f2;
        f2 = f1;
        f1 = max;
    }

    printf("%d\n", max);
    return 0;
}