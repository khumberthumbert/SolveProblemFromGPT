#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <atlstr.h>

int main(void)
{
	char szNameAndPhone[40];
	CString str;
	CString realStr;

	gets_s(szNameAndPhone, 40);

	MultiByteToWideChar(
		CP_ACP,
		0,
		szNameAndPhone,
		-1,
		str.GetBuffer(40),
		40
	);

	str.ReleaseBuffer();

	str.Replace(L" ", L"");
	str.Replace(L"-", L"");
	CString name = str.Left(3);
	CString phone = str.Right(str.GetLength() - 3);
	realStr = name + "," + phone;
	MessageBox(NULL, realStr, L"뭐라고 나올까", MB_OK);

	return 0;
}