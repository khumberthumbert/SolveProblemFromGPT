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
    getchar();  // ���� ���� ����

    while (n--) {
        fgets(str, sizeof(str), stdin);
        //fgets�� ���๮�ڸ� �����ؼ� �޴´�. �׷��� ������� ��.
        str[strcspn(str, "\n")] = '\0';  // ���� ���� ����

        char* start = str;
        for (int i = 0; i <= strlen(str); i++) {
            if (str[i] == ' ' || str[i] == '\0') {
                //str + i - 1 �ǹ� : str[i]�� ���� �˻����� ����
                // str[i] == ' ' �Ǵ� str[i] == '\0'�� ��, �ܾ��� ���� ã�Ҵٴ� �ǹ�
                //���� �ܾ�� ������ ���� str[i - 1]�� �ִ�.
                reverseWord(start, str + i - 1);

                //���� �ܾ��� ���� ��ġ ������Ʈ
                start = str + i + 1;
            }
        }

        printf("%s\n", str);
    }

    return 0;
}
