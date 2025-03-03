#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <string.h>

char arr[1001];
int top = 0;

int main() {

	int N, num;
	scanf_s("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		fgets(arr, 1001, stdin);
		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == ' ' || arr[j] == '\n') {
				for (int k = j - 1; k >= top; k--)
					printf("%c", arr[k]);
				top = j + 1;
				printf(" ");
			}
		}
		printf("\n");
		top = 0;
	}
	return 0;
}