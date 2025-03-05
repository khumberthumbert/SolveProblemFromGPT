#include <stdio.h>

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(arr + i));
	}
}

int main(void)
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	printArray(arr, sizeof(arr) / sizeof(int));
	return 0;
}