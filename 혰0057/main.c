#include <stdio.h>

int add(int a, int b) {	return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main(void)
{
	int a = 0, b = 0;
	char c;
	scanf_s("%d %d %c", &a, &b, &c, sizeof(char) + 1);
	getchar();

	int (*opration)(int, int);

	if (c == '+') {
		opration = add;
	}
	else if (c == '-') {
		opration = subtract;
	}
	else if (c == '*') {
		opration = multiply;
	}
	else if (c == '/') {
		opration = divide;
	}
	else {
		printf("산술 입력식이 잘못 되었습니다.");
		return 1;
	}
	printf("%d", opration(a, b));

	return 0;
}