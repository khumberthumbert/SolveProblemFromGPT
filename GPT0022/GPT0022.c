#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	fopen_s(&fp, "C:/Users/User/Desktop/data.txt", "w");
	char content[100];
	scanf_s("%s", content, sizeof(content));

	fprintf(fp, "%s", content);

	fclose(fp);

	fopen_s(&fp, "C:/Users/User/Desktop/data.txt", "r");

	fgets(content, sizeof(content) , fp);
	printf("%s", content);

	fclose(fp);

	return 0;

}