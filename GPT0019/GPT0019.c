#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FacFunc(int n)
{
	if (n == 1 || n == 0) return 1;

	return FacFunc(n - 1) * (n);
}

int main(void)
{
	int n = 0;
	scanf_s("%d", &n);
	int result = FacFunc(n);
	printf("%d", result);


	return 0;
}