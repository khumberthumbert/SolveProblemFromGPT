#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char hexChars[] = "0123456789ABCDEF";
    char hexStr[33] = { 0 };  // 32�ڸ� + �� ����
    int i;

    srand((unsigned)time(NULL));  // �õ� ����

    for (i = 0; i < 32; i++) {
        int index = rand() % 16;         // 0 ~ 15
        hexStr[i] = hexChars[index];     // �ش� ���� ����
    }

    printf("���� HEX: %s\n", hexStr);
    return 0;
}
