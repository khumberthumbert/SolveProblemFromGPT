#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[50];
    int price;
} Book;

int main(void) {
    printf("�Է��Ϸ��� å �Ǽ��� �Է��ϼ���: ");
    int n = 0;
    scanf_s("%d", &n);
    getchar(); // ���� ���� ����

    // ���� �޸� �Ҵ�
    Book* book = (Book*)malloc(sizeof(Book) * n);
    if (book == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    printf("å �̸�, ����, ������ �Է��ϼ���:\n");
    for (int i = 0; i < n; i++) {
        printf("å %d ����: ", i + 1);
        fgets(book[i].title, sizeof(book[i].title), stdin);
        book[i].title[strcspn(book[i].title, "\n")] = 0; // ���� ���� ����

        printf("å %d ����: ", i + 1);
        fgets(book[i].author, sizeof(book[i].author), stdin);
        book[i].author[strcspn(book[i].author, "\n")] = 0; // ���� ���� ����

        printf("å %d ����: ", i + 1);
        scanf_s("%d", &book[i].price);
        getchar(); // ���� �Է� �� ���� ���� ����
    }

    printf("\n[å ���]\n");
    for (int i = 0; i < n; i++) {
        printf("%d. ����: %s, ����: %s, ����: %d��\n",
            i + 1, book[i].title, book[i].author, book[i].price);
    }

    // �޸� ����
    free(book);

    return 0;
}
