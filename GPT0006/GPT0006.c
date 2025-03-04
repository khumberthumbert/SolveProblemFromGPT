#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Calculator
{
	int (*operation)(int, int);
} Cal;

int add(int a, int b){ return a + b;}

int subtract(int a, int b){	return a - b;}

int multiply(int a, int b){	return a * b;}

int divide(int a, int b){return b != 0 ? a / b : 0;}

int main(void)
{
	unsigned int a, b;
	char op;
	Cal c;
	printf("입력: ");
	scanf_s("%d", &a);
	getchar();
	scanf_s("%c", &op, sizeof(op));
	scanf_s("%d", &b);

	if (op == '+') c.operation = add;
	else if (op == '-') c.operation = subtract;
	else if (op == '*') c.operation = multiply;
	else if (op == '/') c.operation = divide;
	else {
		printf("잘못된 연산자입니다.\n");
		return 1;
	}

	// 계산 수행 및 출력
	printf("출력 : %d %c %d = %d \n", a, op, b, c.operation(a, b));

	return 0;
}