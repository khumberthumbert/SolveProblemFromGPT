#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addOne(int x) {
	return x + 1;
}

int doubleValue(int x) {
	return x * 2;
}

int square(int x) {
	return x * x;
}

int main(void)
{
	char tmp[100] = { 0 };
	char* inTitle = (char*)malloc(strlen(tmp) + 1);
	char* outTitle = (char*)malloc(strlen(tmp) + 1);
	char i_url[100] = { "C:/Users/SAMSUNG/Desktop/" };
	char o_url[100] = { "C:/Users/SAMSUNG/Desktop/" };

	printf("입력 파일명 입력: ");
	scanf_s("%s", inTitle, strlen(tmp) + 1);
	strcat_s(i_url, sizeof(i_url), inTitle);

	printf("출력 파일명 입력: ");
	scanf_s("%s", outTitle, strlen(tmp) + 1);
	strcat_s(o_url, sizeof(o_url), outTitle);

	int selected = 0;
	printf("변환 선택 (1: +1, 2: 두 배, 3: 제곱): ");
	scanf_s("%d", &selected);

	//입력 파일 데이터 입력
	FILE* fp;
	fopen_s(&fp, i_url, "w");

	int inputDummy[5] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++) {
		fprintf(fp, "%d ", inputDummy[i]);
	}

	fclose(fp);

	//입력 파일 읽어서 메모리에 저장.
	fopen_s(&fp, i_url, "r");
	int outputDummy[5];

	for (int i = 0; i < 5; i++) {
		fscanf_s(fp, "%d ", &outputDummy[i]);
	}

	fclose(fp);

	//사용자가 선택한 변환함수 실행
	int (*func)(int);
	if (selected == 1) {
		func = addOne;
		for (int i = 0; i < 5; i++) {
			outputDummy[i] = func(outputDummy[i]);
		}
	}
	else if (selected == 2) {
		func = doubleValue;
		for (int i = 0; i < 5; i++) {
			outputDummy[i] = func(outputDummy[i]);
		}
	}
	else if (selected == 3) {
		func = square;
		for (int i = 0; i < 5; i++) {
			outputDummy[i] = func(outputDummy[i]);
		}
	}

	//변환된 outDummy 데이터 저장하기
	fopen_s(&fp, o_url, "w");

	for (int i = 0; i < 5; i++) {
		fprintf(fp, "%d ", outputDummy[i]);
	}

	fclose(fp);

	//output파일에서 변환된거 메모리로 출력하기
	int printDummy[5] = { 0 };
	fopen_s(&fp, o_url, "r");
	for (int i = 0; i < 5; i++) {
		fscanf_s(fp, "%d ", &printDummy[i]);
	}

	for (int i = 0; i < 5; i++) {
		printf("%d ", printDummy[i]);
	}

	fclose(fp);
	free(inTitle);
	free(outTitle);

	return 0;
}