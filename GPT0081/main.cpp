#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <atlstr.h>

int main(void)
{
	printf("���ڿ��� �Է��ϼ���: ");
	char recvBuf[256];
	scanf_s("%s", recvBuf, 256);

	//printf("%s", recvBuf);
	CString str;

	MultiByteToWideChar(
		CP_ACP,
		0,
		recvBuf,
		-1,
		str.GetBuffer(256),
		256
	);

	str.ReleaseBuffer();
	MessageBox(NULL, str, L"�����ڵ� ���ڿ� Ȯ��", MB_OK);
	return 0;
}