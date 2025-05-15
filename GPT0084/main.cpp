#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[65]; // 64�ڸ� + �� ����
    sprintf_s(buf, "%64s", "");  // ���� 64�� �����

    // 1. ���ڿ� ��ü ��� (�ð� Ȯ�ο�)
    printf("buf ���ڿ� ����:\n[%s]\n", buf);

    // 2. �� ���� �ƽ�Ű �� Ȯ��
    printf("�ƽ�Ű �� (64��):\n");
    for (int i = 0; i < 64; ++i)
    {
        printf("%02d ", (unsigned char)buf[i]); // ���� ���ڸ� 32 ���
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    // 3. ���� üũ
    printf("\nstrlen(buf): %zu\n", strlen(buf));  // ����� 64 ���;� ��

    return 0;
}
