#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input = 0;
	scanf_s("%d", &input);
	printf("�Է��� ��: %d, �ּ�: %p", input, &input);
	return 0;
}