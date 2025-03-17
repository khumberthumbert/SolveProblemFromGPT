#include <stdio.h>

int main(void)
{
	int input = 0;
	scanf_s("%d", &input);
	char* sPrime = "Prime";
	char* sNotPrime = "Not Prime";
	int result = 1;
	for (int i = 2; i <= input - 1; i++)
	{
		if (input % i == 0)
		{
			result = 0;
			break;
		}
		if (input == 2)
		{
			printf("Prime");
			return 0;
		}
	}

	if (result == 1 )
	{
		printf("%s", sPrime);
	}
	else {
		printf("%s", sNotPrime);
	}
	return 0;
}