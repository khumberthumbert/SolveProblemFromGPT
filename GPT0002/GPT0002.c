#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input = 0;
	scanf_s("%d", &input);
	printf("입력한 값: %d, 주소: %p", input, &input);
	return 0;
}