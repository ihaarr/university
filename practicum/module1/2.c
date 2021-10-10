#include <stdio.h>

int main() {
    int num;
	
	printf("Enter a number\n");
	scanf("%d", &num);

	int number = num;
	int backwardNumber = 0;

	while (number > 0)
	{
		backwardNumber = backwardNumber * 10 + number % 10;
		number /= 10;
	}
	if (num == backwardNumber)
		printf("Number is a palindrome\n");
	else
		printf("Number is not a palindrome\n");

	return 0;
}