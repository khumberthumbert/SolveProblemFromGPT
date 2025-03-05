#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int input = 0;
	printf("크기를 입력하세요 : ");
	scanf_s("%d", &input);
	int* arr = (int*)malloc(sizeof(int) * input);

	printf("값을 입력하세요 : ");
	for (int i = 0; i < input; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < input; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);

	return 0;
}