#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char tmp[100] = { 0 };

	//�Է� ���� �Է�
	char* inputTitle = (char*)malloc(strlen(tmp) + 1);
	char* i_url[100] = { "C:/Users/SAMSUNG/Desktop" };
	printf("�Է� ���� ���� �Է��ϼ���: ");
	scanf_s("%s", inputTitle);
	strcat_s(i_url, strlen(tmp) + 1, inputTitle);

	//��� ���� �Է�
	char* outputTitle = (char*)malloc(strlen(tmp) + 1);
	char* o_url[100] = { "C:/Users/SAMSUNG/Desktop" };
	printf("��� ���� ���� �Է��ϼ���: ");
	scanf_s("%s", outputTitle);
	strcat_s(o_url, strlen(tmp) + 1, outputTitle);

	



	return 0;
}