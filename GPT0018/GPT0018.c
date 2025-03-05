#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[50];
	int score;
} Stu;

int main(void)
{
	int n;
	printf("�л� ���� �Է��ϼ��� : ");
	scanf_s("%d", &n);
	Stu* stu = (Stu*)malloc(sizeof(Stu) * n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%s %d",stu[i].name, (unsigned int)sizeof(stu[i].name), &stu[i].score);
	}
	printf("�Է��� �л��� ���� : ");
	for (int i = 0; i < n; i++)
	{
		printf("�̸� : %s ����: %d\n", stu[i].name, stu[i].score);
	}


	free(stu);
	return 0;
}