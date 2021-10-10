#include <stdio.h>

int main() {
    int n, a;
    int sum = 0;
    printf("Enter size of seq: ");
    scanf("%d", &n);    
    while(n > 0) {
        printf("Enter el: ");
        scanf("%d", &a);
        if(a % 10 == 5) 
            sum += a;
        --n;
    }

    if(sum == 0)
        printf("There's no number that ends on 5\n");
    else
        printf("Sum = %d\n", sum);
    return 0;
}