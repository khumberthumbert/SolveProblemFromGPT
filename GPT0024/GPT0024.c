#include <stdio.h>

int FibonacciFunc(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;

	return FibonacciFunc(n - 2) + FibonacciFunc(n - 1);
}

int main(void)
{
	int n = 0;
	printf("피보나치 수열 하고 싶은 자연수 n을 입력하세요 : ");
	scanf_s("%d", &n);

	int result = FibonacciFunc(n);
	printf("답은 : %d", result);
	return 0; 
}