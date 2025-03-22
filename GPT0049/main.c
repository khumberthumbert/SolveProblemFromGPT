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
	printf("몇 명의 사용자 정보를 저장하시겠습니까? (최대 5명): ");
	scanf_s("%d", &countP);
	getchar();

	if (countP > 5 || countP < 0) {
		printf("사용자 지정에 오류가 생겼습니다.");
		return 1;
	}
	for (int i = 0; i < countP; i++)
	{
		
		printf("이름: ");
		scanf_s("%s", per[i].name, 50);
		printf("나이: ");
		scanf_s("%d", &per[i].age);
		printf("이메일: ");
		scanf_s("%s", per[i].email, 50);
		printf("\n");
		fprintf(fp, "%s %d %s", per[i].name, per[i].age, per[i].email);

	}
	fclose(fp);

	fopen_s(&fp, "C:/Users/User/Desktop/user.dat", "rb");
	
	for (int i = 0; i < countP; i++)
	{
		fgets(per[i].name, sizeof(per[i].name), fp);
		per[i].name[strcspn(per[i].name, "\n")] = 0;  // 개행 문자 제거

		fscanf_s(fp, "%d", &per[i].age);
		fgetc(fp); // 숫자 뒤에 남아있는 개행 문자 제거

		fgets(per[i].email, sizeof(per[i].email), fp);
		per[i].email[strcspn(per[i].email, "\n")] = 0; // 개행 문자 제거

		printf("%d %s %d %s\n", i + 1, per[i].name, per[i].age, per[i].email);
	}
	
	fclose(fp);


	return 0;
}