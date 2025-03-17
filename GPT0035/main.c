#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int input = 0;
	scanf_s("%d", &input);

	for (int i = 1; i <= input; i++)
	{
		if (input % i == 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}