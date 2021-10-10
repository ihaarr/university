#include <stdio.h>

int main() { 
    int n, sign, flag;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; ++i) {
        printf("Enter a el: ");
        scanf("%d", &arr[i]);
    }

    flag = 1;
    int temp = arr[0];
    int i = 1;
    while (temp == 0)
    {
        temp = arr[i];
        ++i;
    }

    if(temp < 0)
        sign = 0;
    else
        sign = 1;
    
    for(; i < n; ++i) {
        if(arr[i] != 0) {
            if(!( (arr[i] > 0 && sign != 1) || (arr[i] < 0 && sign != 0) ) ) {
                flag = 0;
                break;
            } else
                sign = !sign;
        }
    }

    if(flag == 0)
        printf("False\n");
    else
        for(int i = 0; i < n; ++i)
            if(arr[i] != 0)
                printf("arr[%d] = %d\n", i, arr[i]);
    return 0;
}