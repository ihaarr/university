#include <iostream>

//Найти все натуральные числа, меньшие заданного числа N, при делении на которые число N дает остаток в виде степени тройки.
const float N = 27;
bool isPowOfThree(float num) {
    for(float x = 1; x <= num; x*=3) {
        if(x == num) return true;
    }

    return false;
}

void print_all_numbers() {
    for(int i = 1; i < N; i++) {
        if(isPowOfThree(N / i))
            printf("%d is pow of 3\n", (int)(N / i));
    }
}

int main() {
    print_all_numbers();
    return 0;
}