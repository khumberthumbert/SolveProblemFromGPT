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
	printf("�̸��� ���̸� �Է��ϼ���: ");

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
	str.Format(L"�̸�: %s, ����: %d��", nameStr.GetString(), age);
	MessageBox(NULL, str, L"�����ڵ�� �� ��ȯ�Ǿ����� Ȯ��", MB_OK);
	return 0;
}