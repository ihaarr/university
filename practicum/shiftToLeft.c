#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("\nEnter a number: ");
        scanf("%d", &arr[i]);
    }

    int x;
    printf("\nEnter a shift: ");
    scanf("%d", &x);
    if(x > n) {
        x = x % n;
    }
    int k = n - x;
    int temp1, temp2;
    for(int j = 0; j < k; ++j) {
        temp1 = arr[0];
        for(int i = 1; i < n; ++i) {
            if(i + 1 == n) {
                temp2 = arr[i];
                arr[i] = temp1;
                arr[0] = temp2;
            } else {
                temp2 = arr[i];
                arr[i] = temp1;
                temp1 = temp2;
            }
        }
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}