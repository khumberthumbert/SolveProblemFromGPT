#include <stdio.h>
#include <stdlib.h>


typedef struct Student
{
	char name[30];
	int score;
}Student;

int main(void)
{
	int n = 0;
	printf("입력할 학생 수 : ");
	scanf_s("%d", &n);
	Student* stu = (Student*)malloc(sizeof(Student) * n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", stu[i].name, (unsigned int)sizeof(stu->name));
		scanf_s("%d", &stu[i].score);
	}
	FILE* fp;

	fopen_s(&fp, "C:/Users/User/Desktop/grades.txt", "w");

	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %d\n", stu[i].name, stu[i].score);
	}

	fclose(fp);

	fopen_s(&fp, "C:/Users/User/Desktop/grades.txt", "r");

	for (int i = 0; i < n; i++)
	{
		fscanf_s(fp, "%s", stu[i].name, (unsigned int)sizeof(stu[i].name));
		fscanf_s(fp, "%d", &stu[i].score);
		printf("%d. %s - %d점\n", i + 1, stu[i].name, stu[i].score);
	}

	fclose(fp);

	free(stu);

	return 0;
}