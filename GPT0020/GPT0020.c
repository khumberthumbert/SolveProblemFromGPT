#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n = 0;
	printf("������ ������ �Է� �ϼ���: ");
	scanf_s("%d", &n);
	int* sum = (int*)malloc(sizeof(int) * n);
	printf("������ ������ŭ �Է��ϼ��� : ");
	int nInt = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &nInt);
		sum[i] = nInt;
		result += sum[i];
	}

	printf("������ ������ %d �Դϴ�.", result);
	return 0;
}