#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	printf("ũ�⸦ �Է��ϼ��� : ");
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);

	printf("���ڸ� �Է��ϼ���: ");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	int tmp = 0;
	tmp = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > tmp)
		{
			tmp = arr[i];
		}
	}
	printf("�ִ밪�� %d", tmp);

	free(arr);

	return 0;
}