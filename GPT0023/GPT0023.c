#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b){return a + b;}
int divi(int a, int b) { return a - b; }
int gogo(int a, int b) { return a * b; }
int nana(int a, int b) { return a / b; }

int main(void)
{
	int a = 0, b = 0;
	char c;
	int (*fp)(int, int) = NULL;
	printf("두 개의 정수와 계산식을 입력하세요 (+, -, *, /) : ");
	scanf_s("%d %c %d", &a, &c, 1, & b);
	if (c == '+' ) 
	{
		fp = add;
	}
	else if(c == '-')
	{
		fp = divi;
	}
	else if (c == '*')
	{
		fp = gogo;
	}
	else if (c == '/' && b!= 0)
	{
		fp = nana;
	}

	printf("%d", fp(a, b));

	return 0;
}