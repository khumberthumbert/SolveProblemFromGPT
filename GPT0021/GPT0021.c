#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[50];
	int age;
	int score;

} Stu;

int main(void)
{
	Stu s;
	printf("�л��� �̸��� �Է��ϼ��� : ");
 	scanf_s("%s", s.name, sizeof(s.name));
	printf("�л��� ���̿� ������ �Է��ϼ��� : ");
	scanf_s("%d %d", &s.age, &s.score);
	printf("%s %d %d", s.name, s.age, s.score);
	return 0;
}