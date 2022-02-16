#include <iostream>

int main() {
    char str[] = "hello 25 1 dd";
    int digits[10];
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            digits[str[i] - '0']++;
        }
    }
    for(int i = 9; i >=0; i--) {
        if(digits[i] > 0) {
            for(int j = 0; j < digits[i]; j++) {
                printf("%d", i);
            }
        }
    }

    printf("\n");
    return 0;
}