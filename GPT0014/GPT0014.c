#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
    *b = tmp;
}

int main(void)
{
	int a = 10;
	int b = 20;
	printf("swap Àü %d %d\n", a, b);

	swap(&a, &b);

	printf("swap ÈÄ %d %d", a, b);

	return 0;
}