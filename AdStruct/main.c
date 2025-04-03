#include <stdio.h>
#include <stdlib.h>
#include "contact_list.h"
#include "contact_node.h"
#include "contact.h"

void dummyData(ContactList* myList) {

    // �׽�Ʈ�� ����ó 1
    CONTACT c1 = { "ȫ�浿", "010-1111-2222", "1990-01-01", 100000, 50000 };
    addContact(myList, c1);

    // �׽�Ʈ�� ����ó 2
    CONTACT c2 = { "�迵��", "010-3333-4444", "1995-03-15", 150000, 0 };
    addContact(myList, c2);

    // �׽�Ʈ�� ����ó 3
    CONTACT c3 = { "��ö��", "010-5555-6666", "1988-10-05", 0, 70000 };
    addContact(myList, c3);
}

int main() {
    //����Ʈ ����

    ContactList* myList = createContactList();
    dummyData(myList);

    // ��ü ���
    printAllContacts(myList);

    removeContactByName(myList, "ȫ�浿");
    printAllContacts(myList);

    // �޸� ����
    destroyContactList(myList);

    return 0;
}
