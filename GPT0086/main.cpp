#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <atlstr.h>

int main(void)
{
	char* szTime = (char*)malloc(sizeof(char) * 20);
	gets_s(szTime, 20);

	CString changeTime;

	MultiByteToWideChar(
		CP_ACP,
		0,
		szTime,
		-1,
		changeTime.GetBuffer(20),
		20
	);
	changeTime.ReleaseBuffer();

	changeTime.Replace(L".", L"-");

	MessageBox(NULL, changeTime, L"시간 잘 뽑히나 확인", MB_OK);

	free(szTime);
	return 0;
}