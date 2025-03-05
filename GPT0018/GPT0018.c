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
	printf("학생 수를 입력하세요 : ");
	scanf_s("%d", &n);
	Stu* stu = (Stu*)malloc(sizeof(Stu) * n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%s %d",stu[i].name, (unsigned int)sizeof(stu[i].name), &stu[i].score);
	}
	printf("입력한 학생의 정보 : ");
	for (int i = 0; i < n; i++)
	{
		printf("이름 : %s 점수: %d\n", stu[i].name, stu[i].score);
	}


	free(stu);
	return 0;
}