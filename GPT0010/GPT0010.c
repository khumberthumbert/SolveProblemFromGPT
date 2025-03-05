#include <stdio.h>

int main(void)
{

	int arr[5] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		printf("%d", *arr + i);
	}
	return 0;
}