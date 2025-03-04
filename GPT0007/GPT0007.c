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
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	printf("학생 수 입력: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("이름과 점수를 입력하세요");
		scanf_s("%s", name, (unsigned int)sizeof(name));
		scanf_s("%d", &score);
		fprintf(fp, "%s %d\n", name, score);
	}

	fclose(fp);
	printf("students.txt 파일이 생성 되었습니다.");

	// 파일 읽기 모드로 열기
	if (fopen_s(&fp, "students.txt", "r") != 0) {
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	printf("\n파일에서 읽은 데이터:\n");
	while (fscanf_s(fp, "%s", name, (unsigned int)sizeof(name)) == 1 &&
		fscanf_s(fp, "%d", &score) == 1) {
		printf("%s %d\n", name, score);
	}
	fclose(fp);
	return 0;
}		