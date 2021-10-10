#include <stdio.h>

void reverse(int arr[], const int size) {
    for(int i = 0; i < size / 2; ++i) {
        int temp = arr[size - i - 1];
        arr[size - 1 - i] = arr[i];
        arr[i] = temp;
    }
}

void shiftKTimes() {
    int shift, size;
    printf("Enter a size of seq: ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; ++i) {
        printf("Enter a el: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter a shift: ");
    scanf("%d", &shift);
    if(shift > size) {
        shift %= size;
    }

    reverse(arr + size - shift, shift);
    reverse(arr, size - shift);
    reverse(arr, size);

    for(int i = 0; i < size; ++i)
        printf("el%d = %d\n", i, arr[i]);
}

void shiftOneTime() {
    int shift, size;
    printf("Enter a size of seq: ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; ++i) {
        printf("Enter a el: ");
        scanf("%d", &arr[i]);
    }

    shift = 1;
    reverse(arr, size - shift);
    reverse(arr, size);

    for(int i = 0; i < size; ++i)
        printf("el%d = %d\n", i, arr[i]);
}
int main() {
    shiftOneTime();
    return 0;
}