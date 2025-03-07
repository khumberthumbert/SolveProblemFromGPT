#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int n = 0;
	scanf_s("%d", &n);
	int tmp = 0;
	int* n_Data = (int*)malloc(sizeof(int) * 10000001);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &n_Data[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++)
		{
			if (n_Data[j] > n_Data[j + 1])
			{
				int tmp = n_Data[j];
				n_Data[j] = n_Data[j + 1];
				n_Data[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", n_Data[i]);
	}

	return 0;
}