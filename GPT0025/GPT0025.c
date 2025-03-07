#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n = 0;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &n);
	double* n_arr = (double*)malloc(sizeof(double) * n);

	double result = 0.0;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lf", &n_arr[i]);
		result += n_arr[i];
	}
	printf("%.2f",result / n);


	return 0;
}