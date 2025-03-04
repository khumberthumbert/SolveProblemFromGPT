#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[50];
	int score;
}Student;

int main(void)
{
	int n;
	int score;
	char name[50];
	FILE* fp;

	if (fopen_s(&fp, "students.txt", "w") != 0) {
		printf("������ �� �� �����ϴ�.\n");
		return 1;
	}

	printf("�л� �� �Է�: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("�̸��� ������ �Է��ϼ���");
		scanf_s("%s", name, (unsigned int)sizeof(name));
		scanf_s("%d", &score);
		fprintf(fp, "%s %d\n", name, score);
	}

	fclose(fp);
	printf("students.txt ������ ���� �Ǿ����ϴ�.");

	// ���� �б� ���� ����
	if (fopen_s(&fp, "students.txt", "r") != 0) {
		printf("������ �� �� �����ϴ�.\n");
		return 1;
	}

	printf("\n���Ͽ��� ���� ������:\n");
	while (fscanf_s(fp, "%s", name, (unsigned int)sizeof(name)) == 1 &&
		fscanf_s(fp, "%d", &score) == 1) {
		printf("%s %d\n", name, score);
	}
	fclose(fp);
	return 0;
}		