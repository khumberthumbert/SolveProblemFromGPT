#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_list.h"
#include "contact_node.h"
#include "contact.h"

//����� ����Ʈ ����ü
typedef struct ContactList {
	ContactNode* head;
	ContactNode* tail;
	int size;
} ContactList;

// �����List ���� �Լ�
ContactList* createContactList() {
	ContactList* list = NULL;
	list = (ContactList*)malloc(sizeof(ContactList));

	if (list == NULL) {
		printf("�����Ҵ翡 �����߽��ϴ�\n");
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
};

//����Ʈ �ʱ�ȭ
void destroyContactList(ContactList* list) {

	if (list == NULL) return;

	while (list->head != NULL) {
		ContactNode* curr = list->head;
		ContactNode* next = curr->next;
		free(curr);
		list->head = next;
	}

	free(list);
};

//����Ʈ�� ������ �߰�
void addContact(ContactList* list, CONTACT contact) {
	ContactNode* node;
	node = (ContactNode*)malloc(sizeof(ContactNode));
	node->prev = NULL;
	node->next = NULL;

	node->data = contact;
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	}
	else {
		node->prev = list->tail;
		node->next = NULL; // ���� ���� ����� next�� ������ ����ų��
		list->tail->next = node; // ���� ������ ����� ���� ���. "����Ʈ�� ������ ��尡 �� ��带 ����Ű��"
		list->tail = node; // "�������� ����Ʈ�� ���� �� ���"
	}
	list->size++;

};

//��ü ����Ʈ ���
void printAllContacts(const ContactList* list) {
	if (list == NULL || list->head == NULL) {
		printf("�ּҷ��� ��� �ֽ��ϴ�.\n");
		return;
	}

	ContactNode* curr = list->head;
	printf("===== ��ü ����ó ��� (�� %d��) =====\n", list->size);
	while (curr != NULL) {
		printf("-------------------------\n");
		printf("| �̸� : %s\n", curr->data.name);
		printf("| ��ȭ��ȣ: %s\n", curr->data.phone);
		printf("| ���� : %s\n", curr->data.birthday);
		printf("| ���Ǳ� : %d��\n", curr->data.happyMoney);
		printf("| ���Ǳ� : %d��\n", curr->data.sadMoney);
		printf("-------------------------\n");
		curr = curr->next;
	}
};

//�̸����� �˻�
CONTACT* findContactByName(ContactList* list, const char* name) {
	if (list == NULL) return NULL;

	ContactNode* curr = list->head;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0) {
			return &(curr->data); // ã�� ��� �� ���� ��ü �����͸� ����Ű�� �ּ�
		}
		curr = curr->next;
	}
	return NULL;
};

// �̸����� ����.
void removeContactByName(ContactList* list, const char* name) {
	if (list == NULL || list->head == NULL) return;

	ContactNode* curr = list->head;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0) {
			// ���� ���� ���� next ���
			ContactNode* toDelete = curr;
			ContactNode* nextNode = curr->next;

			// head�� ���
			if (toDelete == list->head) {
				list->head = toDelete->next;
				if (list->head != NULL)
					list->head->prev = NULL;
			}
			// tail�� ���
			else if (toDelete == list->tail) {
				list->tail = toDelete->prev;
				if (list->tail != NULL)
					list->tail->next = NULL;
			}
			// �߰� ���
			else {
				toDelete->prev->next = toDelete->next;
				toDelete->next->prev = toDelete->prev;
			}

			free(toDelete);
			list->size--;
			return;  // ù ��° ��ġ �׸� �����ϰ� ����
		}

		curr = curr->next;
	}
}

