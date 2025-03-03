#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input1 = 0;

	printf("입력: ");
	scanf_s("%d", &input1);

	int* iArr = (int*)malloc(sizeof(int)* input1);

	printf("정수 입력 : ");
	for (int i = 0; i < input1; i++)
	{
		scanf_s("%d", &iArr[i]);
	}
	printf("출력:");
	for (int i = 0; i < input1; i++)
	{
		printf("%d\t", iArr[i]);
	}
	free(iArr);
	return 0;
}