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
	char* cStr[30]; // �ִ� 30���� ���ڿ� ����
	char tmp[30]; // �Է� ���� ���ڿ�
	int count = 0; //�Էµ� ���ڿ� ����

	while (count < 30)
	{
		printf("�Է�: ");
		gets_s(tmp, sizeof(tmp));

		//�� �Է½� ����
		if (strlen(tmp) == 0) break;

		//���� �޸� �Ҵ�
		//strlen(tmp) + 1 �ϴ� ���� -> \0 ���� ��Ű�� ���ؼ�.
		cStr[count] = (char*)malloc(strlen(tmp) + 1);
		if (cStr[count] == NULL)
		{
			printf("�޸� �Ҵ� ����\n");
			return 1; //return 1; �� ������ main()�Լ� �����. -> ������ �����. 0���� ��ȯ�ϸ� ���� ������.
		}

		//���ڿ� ���� �� ������
		strcpy_s(cStr[count], strlen(tmp) + 1, tmp);
		reverseString(cStr[count]);
		count++;
	}

	//��� (������ ���ڿ� ���)
	printf("���:\n");
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", cStr[i]);
	}

	//���� �Ҵ�� �޸� ����
	for (int i = 0; i < count; i++)
	{
		free(cStr[i]);
	}
	return 0;
}
