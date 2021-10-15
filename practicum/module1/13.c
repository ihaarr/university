#include <stdio.h>

/*
* Дано натуральное число n. Определить, какие цифры и сколько раз встречаются в записи числа.
*/
int main() {
    int n;
    int digits[10] = {};
    printf("Enter a number: ");
    scanf("%d", &n);
    while(n > 0) {
        digits[n % 10] += 1;
        n /= 10;
    }

    for(int i = 0; i < 10; ++i) {
        if(digits[i] != 0)
            printf("Digit %d exists %d time(s)\n", i, digits[i]);
    }
    return 0;
}