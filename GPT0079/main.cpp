#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, tries = 0;

    srand((unsigned)time(NULL));       // �õ� ����
    answer = rand() % 100 + 1;         // 1 ~ 100 ���� ����

    printf("���ڸ� ���纸����! (1~100)\n");

    do {
        printf("�Է�: ");
        scanf_s("%d", &guess);
        tries++;

        if (guess < answer)
            printf("�۽��ϴ�.\n");
        else if (guess > answer)
            printf("Ů�ϴ�.\n");
        else
            printf("�����Դϴ�! �õ� Ƚ��: %d\n", tries);

    } while (guess != answer);

    return 0;
}
