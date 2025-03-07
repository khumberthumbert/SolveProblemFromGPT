#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[50];
    int price;
} Book;

int main(void) {
    printf("입력하려는 책 권수를 입력하세요: ");
    int n = 0;
    scanf_s("%d", &n);
    getchar(); // 개행 문자 제거

    // 동적 메모리 할당
    Book* book = (Book*)malloc(sizeof(Book) * n);
    if (book == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("책 이름, 저자, 가격을 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        printf("책 %d 제목: ", i + 1);
        fgets(book[i].title, sizeof(book[i].title), stdin);
        book[i].title[strcspn(book[i].title, "\n")] = 0; // 개행 문자 제거

        printf("책 %d 저자: ", i + 1);
        fgets(book[i].author, sizeof(book[i].author), stdin);
        book[i].author[strcspn(book[i].author, "\n")] = 0; // 개행 문자 제거

        printf("책 %d 가격: ", i + 1);
        scanf_s("%d", &book[i].price);
        getchar(); // 숫자 입력 후 개행 문자 제거
    }

    printf("\n[책 목록]\n");
    for (int i = 0; i < n; i++) {
        printf("%d. 제목: %s, 저자: %s, 가격: %d원\n",
            i + 1, book[i].title, book[i].author, book[i].price);
    }

    // 메모리 해제
    free(book);

    return 0;
}
