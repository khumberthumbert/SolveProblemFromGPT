#include <stdio.h>

#define MAX 50

int n;  // ��� ��
char graph[MAX][MAX];  // ���� ģ�� ���� ('Y' or 'N')
int matrix[MAX][MAX];  // ���ڷ� ��ȯ�� ģ�� ����

int main() {
    scanf("%d", &n); // ��� �� �Է�

    // ���� ��� �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        scanf("%s", graph[i]); // ���ڿ� �Է¹ޱ�
    }

    // 'Y'�� 1��, 'N'�� 0���� ��ȯ�Ͽ� matrix�� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (graph[i][j] == 'Y') ? 1 : 0;
        }
    }

    int maxFriends = 0;  // 2-ģ�� �ִ�

    // �� ���(i)���� 2-ģ�� ���� ���
    for (int i = 0; i < n; i++) {
        int count = 0; // 2-ģ�� ��

        // �湮 �迭 (�ڱ� �ڽ� ����)
        int visited[MAX] = { 0 };

        // ���� ģ�� (1-ģ��) Ž��
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) { // 1-ģ��
                visited[j] = 1; // �湮 ǥ��
                for (int k = 0; k < n; k++) {
                    if (matrix[j][k] == 1) { // 1-ģ���� ģ�� (2-ģ��)
                        visited[k] = 1;
                    }
                }
            }
        }

        // 2-ģ�� �� ���� (�ڱ� �ڽ� ����)
        for (int j = 0; j < n; j++) {
            if (i != j && visited[j]) {
                count++;
            }
        }

        // �ִ� ����
        if (count > maxFriends) {
            maxFriends = count;
        }
    }

    // ��� ���
    printf("%d\n", maxFriends);

    return 0;
}
