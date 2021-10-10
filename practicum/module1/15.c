#include <stdio.h>

int main() {
    int n, c;
    int index = -1;
    printf("Enter a size of array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter a number C: ");
    scanf("%d", &c);
    for(int i = 0; i < n; ++i) {
        if(arr[i] == c) {
            index = i;
            break;
        }
    }

    if(index != -1)
        printf("Index = %d", index);
    else
        printf("There's no element = C\n");
    return 0;
}