#include <stdio.h>
#include <string.h>

void reverseWord(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    char str[1001];

    scanf_s("%d", &n);
    getchar();  // 개행 문자 제거

    while (n--) {
        fgets(str, sizeof(str), stdin);
        //fgets가 개행문자를 포함해서 받는다. 그래서 지워줘야 함.
        str[strcspn(str, "\n")] = '\0';  // 개행 문자 제거

        char* start = str;
        for (int i = 0; i <= strlen(str); i++) {
            if (str[i] == ' ' || str[i] == '\0') {
                //str + i - 1 의미 : str[i]는 현재 검사중인 문자
                // str[i] == ' ' 또는 str[i] == '\0'일 때, 단어의 끝을 찾았다는 의미
                //실제 단어는 마지막 문자 str[i - 1]에 있다.
                reverseWord(start, str + i - 1);

                //다음 단어의 시작 위치 업데이트
                start = str + i + 1;
            }
        }

        printf("%s\n", str);
    }

    return 0;
}
