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
	printf("�Ǻ���ġ ���� �ϰ� ���� �ڿ��� n�� �Է��ϼ��� : ");
	scanf_s("%d", &n);

	int result = FibonacciFunc(n);
	printf("���� : %d", result);
	return 0; 
}