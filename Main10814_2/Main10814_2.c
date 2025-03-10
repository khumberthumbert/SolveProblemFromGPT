#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    int age;
    char name[101];
    int index;  // 입력 순서 유지하기 위한 인덱스
} User;

// 비교 함수 (나이를 기준으로 정렬, 나이가 같다면 입력 순서 유지)
int compare(const void* a, const void* b) {
    User* userA = (User*)a;
    User* userB = (User*)b;

    if (userA->age == userB->age) {
        return userA->index - userB->index; // 입력 순서 유지
    }
    return userA->age - userB->age; // 나이 오름차순 정렬
}

int main(void) {
    int n;
    scanf("%d", &n);

    User* user = (User*)malloc(sizeof(User) * n);
    if (user == NULL) {  // 메모리 할당 실패 체크
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &user[i].age, user[i].name);  // 개행 문자 문제 해결
        user[i].index = i;  // 원래 입력 순서 저장
    }

    // qsort 사용 (O(n log n))
    qsort(user, n, sizeof(User), compare);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", user[i].age, user[i].name);
    }

    free(user);
    return 0;
}
