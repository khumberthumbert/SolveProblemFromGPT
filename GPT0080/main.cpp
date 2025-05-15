#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char hexChars[] = "0123456789ABCDEF";
    char hexStr[33] = { 0 };  // 32자리 + 널 문자
    int i;

    srand((unsigned)time(NULL));  // 시드 설정

    for (i = 0; i < 32; i++) {
        int index = rand() % 16;         // 0 ~ 15
        hexStr[i] = hexChars[index];     // 해당 문자 선택
    }

    printf("랜덤 HEX: %s\n", hexStr);
    return 0;
}
