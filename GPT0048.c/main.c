#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* file;
	
	char* str = (char*)malloc(101);
	int age;

	printf("이름을 입력하세요: ");
	scanf_s("%s", str, 101);
	printf("나이를 입력하세요: ");
	scanf_s("%d", &age);

	if (fopen_s(&file, "C:/Users/User/data2.txt", "w") != 0 || file == NULL) {
		printf("FILE OPEN ERROR!!");
		free(str);
		return 1;
	}
	fprintf(file, "%s %d\n", str, age);
	
	fclose(file);

	fopen_s(&file, "C:/Users/User/data2.txt", "r");

	fscanf_s(file, "%s %d", str, 101, &age);
	printf("%s %d", str, age);

	fclose(file);
	free(str);

	return 0;
}