#include <stdio.h>

int main(void)
{
	int num = 10;
	int* ptr = &num;

	printf("%d", *ptr);

	return 0;
}