#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�����͸� ���� ���ڿ��迭 ������ ����.
int main(void)
{
	char* cHello[50]; //���ڿ��� ������ ������ �迭
	char tmp[50]; //�Է� ���� ���ڿ� ����
	int count = 0; //�Էµ� ���ڿ� ����

	while (count < 50)
	{
		printf("�Է�: ");
		gets_s(tmp, sizeof(tmp));

		//�Է� ������ ����
		if (strlen(tmp) == 0) break;

		//���� �޸� �Ҵ�
		cHello[count] = (char*)malloc(strlen(tmp) + 1);
		if (cHello[count] == NULL) {
			printf("�޸� �Ҵ� ����\n");
			return 1;
		}

		//���ڿ� ����
		strcpy_s(cHello[count], strlen(tmp) + 1, tmp);
		count++;
	}
	//���� ���(���ڿ� ������)
	printf("���:\n");
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