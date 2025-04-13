#include <stdio.h>

int square(int x) { return x * x; };
int triple(int x) { return 3 * x; };
int negate(int x) { return -x; };

void processArray(int* arr, int size, int (*func)(int)) {
		for (int i = 0; i < size; i++) {
			arr[i] = func(arr[i]);
		}
};

int main(void)
{
	int (*func)(int);
	int input = 0;
	printf("�� ���� ������ ��� �迭�� ����ǰ���? ");
	scanf_s("%d", &input);
	printf("���� �迭�� �Է��ϼ��� : ");
	int a[100] = { 0 };

	for (int i = 0; i < input; i++)
	{
		scanf_s("%d", &a[i]);
	}

	printf("� ������ �ұ��? (1: ����, 2: 3��, 3: ������) : ");

	int input1 = 0;
	scanf_s("%d", &input1);

	if (input1 == 1) {
		func = square;
	}
	else if (input1 == 2) {
		func = triple;
	}
	else if (input1 == 3) {
		func = negate;
	}else {
		printf("�ùٸ��� ���� �����Դϴ�.\n");
		return 1;
	}

	processArray(a, input, func);

	printf("ó�� ���: ");
	for (int i = 0; i < input; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}