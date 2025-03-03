#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GPT0005.h"

void reverseString(char* str)
{
	int left = 0;
	int right = strlen(str) - 1;

	//swap
	while (left < right)
	{
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;

		left++;
		right--;
	}
}

int main(void)
{
	char* cStr[30]; // 최대 30개의 문자열 저장
	char tmp[30]; // 입력 받을 문자열
	int count = 0; //입력된 문자열 개수

	while (count < 30)
	{
		printf("입력: ");
		gets_s(tmp, sizeof(tmp));

		//빈 입력시 종료
		if (strlen(tmp) == 0) break;

		//동적 메모리 할당
		//strlen(tmp) + 1 하는 이유 -> \0 포함 시키기 위해서.
		cStr[count] = (char*)malloc(strlen(tmp) + 1);
		if (cStr[count] == NULL)
		{
			printf("메모리 할당 실패\n");
			return 1; //return 1; 을 만나면 main()함수 종료됨. -> 비정상 종료다. 0으로 반환하면 정상 종료임.
		}

		//문자열 복사 후 뒤집기
		strcpy_s(cStr[count], strlen(tmp) + 1, tmp);
		reverseString(cStr[count]);
		count++;
	}

	//출력 (뒤집힌 문자열 출력)
	printf("출력:\n");
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", cStr[i]);
	}

	//동적 할당된 메모리 해제
	for (int i = 0; i < count; i++)
	{
		free(cStr[i]);
	}
	return 0;
}
