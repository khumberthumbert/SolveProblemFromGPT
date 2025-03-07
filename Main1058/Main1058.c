#include <stdio.h>

#define MAX 50

int n;  // 사람 수
char graph[MAX][MAX];  // 원본 친구 관계 ('Y' or 'N')
int matrix[MAX][MAX];  // 숫자로 변환된 친구 관계

int main() {
    scanf("%d", &n); // 사람 수 입력

    // 인접 행렬 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%s", graph[i]); // 문자열 입력받기
    }

    // 'Y'를 1로, 'N'을 0으로 변환하여 matrix에 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (graph[i][j] == 'Y') ? 1 : 0;
        }
    }

    int maxFriends = 0;  // 2-친구 최댓값

    // 각 사람(i)별로 2-친구 수를 계산
    for (int i = 0; i < n; i++) {
        int count = 0; // 2-친구 수

        // 방문 배열 (자기 자신 제외)
        int visited[MAX] = { 0 };

        // 직접 친구 (1-친구) 탐색
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) { // 1-친구
                visited[j] = 1; // 방문 표시
                for (int k = 0; k < n; k++) {
                    if (matrix[j][k] == 1) { // 1-친구의 친구 (2-친구)
                        visited[k] = 1;
                    }
                }
            }
        }

        // 2-친구 수 세기 (자기 자신 제외)
        for (int j = 0; j < n; j++) {
            if (i != j && visited[j]) {
                count++;
            }
        }

        // 최댓값 갱신
        if (count > maxFriends) {
            maxFriends = count;
        }
    }

    // 결과 출력
    printf("%d\n", maxFriends);

    return 0;
}
