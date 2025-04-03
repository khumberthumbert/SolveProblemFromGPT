#include <stdio.h>
#include "contact.h"

typedef struct ContactList ContactList; // ������ �����ͷ� ����

// ����Ʈ�� ���� ����/����
ContactList* createContactList(); // ����Ʈ ����
void destroyContactList(ContactList* list); // ����Ʈ �ʱ�ȭ

// ������ �߰�/����
void addContact(ContactList* list,CONTACT contact);	// �� ����ó �߰�
void removeContactByName(ContactList* list, const char* name);	// �̸����� ����

// ��ȸ
CONTACT* findContactByName(ContactList* list, const char* name); // �̸����� �˻�
void printAllContacts(const ContactList* list); // ��ü ���

// ���
int getTotalHappyMoney(); // �� ���Ǳ� �հ�
int getTotalSadMoney(); // �� ���Ǳ� �հ�