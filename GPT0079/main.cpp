#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, tries = 0;

    srand((unsigned)time(NULL));       // 시드 설정
    answer = rand() % 100 + 1;         // 1 ~ 100 난수 생성

    printf("숫자를 맞춰보세요! (1~100)\n");

    do {
        printf("입력: ");
        scanf_s("%d", &guess);
        tries++;

        if (guess < answer)
            printf("작습니다.\n");
        else if (guess > answer)
            printf("큽니다.\n");
        else
            printf("정답입니다! 시도 횟수: %d\n", tries);

    } while (guess != answer);

    return 0;
}
