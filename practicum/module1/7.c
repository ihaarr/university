#include <stdio.h>

/*
* Дана последовательность целых чисел. Среди отрицательных элементов найти максимальный элелемент и его порядковый номер
*/
int main() {
    int n, a, b, max;
    printf("Enter size of seq: ");
    scanf("%d", &n);
    printf("Enter first el: ");
    scanf("%d", &a);
    max = a;
    int index = 1;
    printf("Enter other elements: ");
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &b);
        if(b > 0) { //Проверка на то, что число положительное
            if(max > 0 && max < b) { //если да, то проверяем максимальное число на положительность и меньше ли оно
                max = b;
                index = i;
            }
        }
        else
            if(max < b) {//Больше ли отрицательное число, максимального отрицательного числа
                max = b;
                index = i;
            }
    }

    printf("index = %d\n max = %d\n", index, max);
    return 0;
}