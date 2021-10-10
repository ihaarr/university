#include <stdio.h>

int main() {
    int n, m, sum, count;
    printf("Enter n: ");
    scanf("%d", &n);
    sum = 0;
    count = 0;
    m = n;
    while(m > 0) {
        sum += m % 10;
        m /= 10;
        ++count;
    }

    printf("Сумма = %d\n Количество = %d\n", sum, count);
    return 0;
}