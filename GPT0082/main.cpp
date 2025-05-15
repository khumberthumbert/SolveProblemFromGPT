#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <atlstr.h>

int main(void)
{
	int age = 0;
	char name[30];
	CString str;
	CString nameStr;
	printf("이름과 나이를 입력하세요: ");

	scanf_s("%s %d", name, 30, &age);

	MultiByteToWideChar(
		CP_ACP,
		0,
		name,
		-1,
		nameStr.GetBuffer(30),
		30
	);
	nameStr.ReleaseBuffer();
	str.Format(L"이름: %s, 나이: %d세", nameStr.GetString(), age);
	MessageBox(NULL, str, L"유니코드로 잘 변환되었는지 확인", MB_OK);
	return 0;
}