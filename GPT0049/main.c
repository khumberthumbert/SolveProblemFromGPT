#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
	char name[50];
	int age;
	char email[50];
} Person;

int main(void)
{
	Person per[5];
	FILE* fp;
	fopen_s(&fp, "C:/Users/User/Desktop/user.dat", "wb");
	int countP = 0;
	printf("�� ���� ����� ������ �����Ͻðڽ��ϱ�? (�ִ� 5��): ");
	scanf_s("%d", &countP);
	getchar();

	if (countP > 5 || countP < 0) {
		printf("����� ������ ������ ������ϴ�.");
		return 1;
	}
	for (int i = 0; i < countP; i++)
	{
		
		printf("�̸�: ");
		scanf_s("%s", per[i].name, 50);
		printf("����: ");
		scanf_s("%d", &per[i].age);
		printf("�̸���: ");
		scanf_s("%s", per[i].email, 50);
		printf("\n");
		fprintf(fp, "%s %d %s", per[i].name, per[i].age, per[i].email);

	}
	fclose(fp);

	fopen_s(&fp, "C:/Users/User/Desktop/user.dat", "rb");
	
	for (int i = 0; i < countP; i++)
	{
		fgets(per[i].name, sizeof(per[i].name), fp);
		per[i].name[strcspn(per[i].name, "\n")] = 0;  // ���� ���� ����

		fscanf_s(fp, "%d", &per[i].age);
		fgetc(fp); // ���� �ڿ� �����ִ� ���� ���� ����

		fgets(per[i].email, sizeof(per[i].email), fp);
		per[i].email[strcspn(per[i].email, "\n")] = 0; // ���� ���� ����

		printf("%d %s %d %s\n", i + 1, per[i].name, per[i].age, per[i].email);
	}
	
	fclose(fp);


	return 0;
}