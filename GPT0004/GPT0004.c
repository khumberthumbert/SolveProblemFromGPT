#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//포인터를 통한 문자열배열 뒤집기 문제.
int main(void)
{
	char* cHello[50]; //문자열을 저장할 포인터 배열
	char tmp[50]; //입력 받을 문자열 버퍼
	int count = 0; //입력된 문자열 개수

	while (count < 50)
	{
		printf("입력: ");
		gets_s(tmp, sizeof(tmp));

		//입력 없으면 종료
		if (strlen(tmp) == 0) break;

		//동적 메모리 할당
		cHello[count] = (char*)malloc(strlen(tmp) + 1);
		if (cHello[count] == NULL) {
			printf("메모리 할당 실패\n");
			return 1;
		}

		//문자열 복사
		strcpy_s(cHello[count], strlen(tmp) + 1, tmp);
		count++;
	}
	//역순 출력(문자열 뒤집기)
	printf("출력:\n");
	for (int i = count - 1; i >= 0; i--)
	{
		printf("%s\n", cHello[i]);
	}

	for (int i = 0; i < count; i++)
	{
		free(cHello[i]);
	}

	return 0;
}