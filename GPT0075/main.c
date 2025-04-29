#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char tmp[100];
    char* strInput = (char*)malloc(strlen(tmp) + 1);

    if (strInput == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("문자열 입력: ");
    scanf_s("%s", strInput, strlen(tmp) + 1);

    
    FILE* fp;
    fopens_s(&fp, "C:/Users/SAMSUNG/Desktop/inputFiles", "w");
    int arr[5] = { 1,2,3,4,5 };
    fprintf(fp, arr);
    fclose(fp);



    free(strInput);
    return 0;
}
