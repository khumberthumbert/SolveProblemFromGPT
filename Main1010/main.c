#include <stdio.h>
#include <stdlib.h>

int factorial(int input) {
	if (input <= 1) return 1;
	return  input * factorial(input - 1);
}

int combFunc(int input1, int input2) {
	int result = factorial(input2) / (factorial(input1)) * (factorial((input2 - input1)));
	return result;
	
}

int main(void)
{
	int input1 = 0, input2 = 0, N = 0;

	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %d", &input1, &input2);
		arr[i] = combFunc(input1, input2);
		
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}

	free(arr);
	return 0;
}