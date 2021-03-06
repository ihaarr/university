#include <stdio.h>
#include <stdbool.h>

/* Дан целочисленный массив размерности n. Определить, является ли последовательность элементов, находящиеся
*  между первым элементом массива, являющегося совершенным числом, и последним элементом массива, являющегося
*  совершенным числом, арифмитической прогрессией. Если такой последовательности нет, вывести сообщение.
*/

//min n = 3, т.к только при таких n существует последовательность
const int n = 3;
int main() {
    int arr[n], d;
    bool flag = true;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    d = arr[2] - arr[1];

    for(int i = 3; i < n - 1; ++i) {
        if(arr[i] - arr[i - 1] != d) {
            flag = false;
            break;
        }
    }

    if(flag)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}