#include <stdio.h>

/*
*   Дано натуральное число n. Определить кол-во и сумму цифр в заданном числе
*/
int main() {
    int n, m, sum, count;
    printf("Enter n: ");
    scanf("%d", &n);
    sum = 0; //Сумма цифр
    count = 0; //Кол-во цифр
    m = n;
    while(m > 0) {
        sum += m % 10;
        m /= 10;
        ++count;
    }

    printf("Сумма = %d\n Количество = %d\n", sum, count);
    return 0;
}