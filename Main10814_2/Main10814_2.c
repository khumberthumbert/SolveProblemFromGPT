#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    int age;
    char name[101];
    int index;  // �Է� ���� �����ϱ� ���� �ε���
} User;

// �� �Լ� (���̸� �������� ����, ���̰� ���ٸ� �Է� ���� ����)
int compare(const void* a, const void* b) {
    User* userA = (User*)a;
    User* userB = (User*)b;

    if (userA->age == userB->age) {
        return userA->index - userB->index; // �Է� ���� ����
    }
    return userA->age - userB->age; // ���� �������� ����
}

int main(void) {
    int n;
    scanf("%d", &n);

    User* user = (User*)malloc(sizeof(User) * n);
    if (user == NULL) {  // �޸� �Ҵ� ���� üũ
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &user[i].age, user[i].name);  // ���� ���� ���� �ذ�
        user[i].index = i;  // ���� �Է� ���� ����
    }

    // qsort ��� (O(n log n))
    qsort(user, n, sizeof(User), compare);

    // ��� ���
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", user[i].age, user[i].name);
    }

    free(user);
    return 0;
}
