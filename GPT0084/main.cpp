#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[65]; // 64자리 + 널 종료
    sprintf_s(buf, "%64s", "");  // 공백 64개 만들기

    // 1. 문자열 전체 출력 (시각 확인용)
    printf("buf 문자열 내용:\n[%s]\n", buf);

    // 2. 각 문자 아스키 값 확인
    printf("아스키 값 (64개):\n");
    for (int i = 0; i < 64; ++i)
    {
        printf("%02d ", (unsigned char)buf[i]); // 공백 문자면 32 출력
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    // 3. 길이 체크
    printf("\nstrlen(buf): %zu\n", strlen(buf));  // 결과는 64 나와야 함

    return 0;
}
