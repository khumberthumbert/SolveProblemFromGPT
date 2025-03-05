#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int arr[2][3] = { {1,2,3}, {4,5,6} };
	int* p = arr;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", *(p + (i * 3) + j));
			
		}
	}


	return 0;
}