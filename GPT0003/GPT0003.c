#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input1 = 0;

	printf("�Է�: ");
	scanf_s("%d", &input1);

	int* iArr = (int*)malloc(sizeof(int)* input1);

	printf("���� �Է� : ");
	for (int i = 0; i < input1; i++)
	{
		scanf_s("%d", &iArr[i]);
	}
	printf("���:");
	for (int i = 0; i < input1; i++)
	{
		printf("%d\t", iArr[i]);
	}
	free(iArr);
	return 0;
}