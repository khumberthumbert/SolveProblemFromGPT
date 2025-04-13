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
	printf("몇 개의 정수를 담는 배열을 만들건가요? ");
	scanf_s("%d", &input);
	printf("정수 배열을 입력하세요 : ");
	int a[100] = { 0 };

	for (int i = 0; i < input; i++)
	{
		scanf_s("%d", &a[i]);
	}

	printf("어떤 연산을 할까요? (1: 제곱, 2: 3배, 3: 음수로) : ");

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
		printf("올바르지 않은 선택입니다.\n");
		return 1;
	}

	processArray(a, input, func);

	printf("처리 결과: ");
	for (int i = 0; i < input; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}