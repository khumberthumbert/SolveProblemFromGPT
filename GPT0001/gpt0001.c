#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;

	scanf_s("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int result = a + b + c + d + e;
	printf("Че : %d, ЦђБе : %.2f", result, (double)result / 5);
}