#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n = 0;
	printf("정수의 개수를 입력 하세요: ");
	scanf_s("%d", &n);
	int* sum = (int*)malloc(sizeof(int) * n);
	printf("정수를 개수만큼 입력하세요 : ");
	int nInt = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &nInt);
		sum[i] = nInt;
		result += sum[i];
	}

	printf("정수의 총합은 %d 입니다.", result);
	return 0;
}