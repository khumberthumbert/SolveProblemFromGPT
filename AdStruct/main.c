#include <stdio.h>
#include <stdlib.h>
#include "contact_list.h"
#include "contact_node.h"
#include "contact.h"

void dummyData(ContactList* myList) {

    // 테스트용 연락처 1
    CONTACT c1 = { "홍길동", "010-1111-2222", "1990-01-01", 100000, 50000 };
    addContact(myList, c1);

    // 테스트용 연락처 2
    CONTACT c2 = { "김영희", "010-3333-4444", "1995-03-15", 150000, 0 };
    addContact(myList, c2);

    // 테스트용 연락처 3
    CONTACT c3 = { "이철수", "010-5555-6666", "1988-10-05", 0, 70000 };
    addContact(myList, c3);
}

int main() {
    //리스트 생성

    ContactList* myList = createContactList();
    dummyData(myList);

    // 전체 출력
    printAllContacts(myList);

    removeContactByName(myList, "홍길동");
    printAllContacts(myList);

    // 메모리 정리
    destroyContactList(myList);

    return 0;
}
