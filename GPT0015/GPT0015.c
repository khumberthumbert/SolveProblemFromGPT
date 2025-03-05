#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverseString(char* str)
{
	int len = strlen(str);

	for (int i = 0; i < len/2; i++)
	{
		char tmp;
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	printf("%s", str);

}

int main(void)
{
	char* arr = (char*)malloc(sizeof(char) * 50);
	printf("문장을 입력하세요: ");
	gets_s(arr, 50);

	reverseString(arr);

	free(arr);

	return 0;
}