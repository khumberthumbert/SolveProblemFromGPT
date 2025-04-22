#include <stdio.h>
#include <stdlib.h>

int factorial(int input) {
	if (input <= 1) return 1;
	return  input * factorial(input - 1);
}

//long long combFunc(int input1, int input2) {
//	long long result = factorial(input2) / (factorial(input1) * factorial(input2 - input1));
//	return result;
//	
//}

long long combFunc(int r, int n) {
	long long result = 1;
	for (int i = 1; i <= r; i++) {
		result = result * (n - i + 1) / i;
	}
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