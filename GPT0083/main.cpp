#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <atlstr.h>

int main(void)
{
	CString jumin;
	CString masked;
	char juminBuf[20];

	printf("�ֹε�Ϲ�ȣ�� �Է��ϼ���: ");
	scanf_s("%s", juminBuf, (unsigned)sizeof(juminBuf));
	MultiByteToWideChar(
		CP_ACP,
		0,
		juminBuf,
		-1,
		jumin.GetBuffer(20),
		20
	);
	jumin.ReleaseBuffer();
	masked = jumin.Left(8) + CString('*', 6);

	MessageBox(NULL, masked, L"Ȯ�ο�", MB_OK);

	return 0;
}