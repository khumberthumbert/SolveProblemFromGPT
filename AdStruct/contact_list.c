#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_list.h"
#include "contact_node.h"
#include "contact.h"

//양방향 리스트 구조체
typedef struct ContactList {
	ContactNode* head;
	ContactNode* tail;
	int size;
} ContactList;

// 양방향List 생성 함수
ContactList* createContactList() {
	ContactList* list = NULL;
	list = (ContactList*)malloc(sizeof(ContactList));

	if (list == NULL) {
		printf("동적할당에 실패했습니다\n");
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
};

//리스트 초기화
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

//리스트에 데이터 추가
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
		node->next = NULL; // 새로 만든 노드의 next를 누구를 가리킬지
		list->tail->next = node; // 기존 마지막 노드의 다음 노드. "리스트의 마지막 노드가 새 노드를 가리키게"
		list->tail = node; // "이제부터 리스트의 끝은 이 노드"
	}
	list->size++;

};

//전체 리스트 출력
void printAllContacts(const ContactList* list) {
	if (list == NULL || list->head == NULL) {
		printf("주소록이 비어 있습니다.\n");
		return;
	}

	ContactNode* curr = list->head;
	printf("===== 전체 연락처 목록 (총 %d명) =====\n", list->size);
	while (curr != NULL) {
		printf("-------------------------\n");
		printf("| 이름 : %s\n", curr->data.name);
		printf("| 전화번호: %s\n", curr->data.phone);
		printf("| 생일 : %s\n", curr->data.birthday);
		printf("| 축의금 : %d원\n", curr->data.happyMoney);
		printf("| 조의금 : %d원\n", curr->data.sadMoney);
		printf("-------------------------\n");
		curr = curr->next;
	}
};

//이름으로 검색
CONTACT* findContactByName(ContactList* list, const char* name) {
	if (list == NULL) return NULL;

	ContactNode* curr = list->head;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0) {
			return &(curr->data); // 찾은 사람 한 명의 전체 데이터를 가리키는 주소
		}
		curr = curr->next;
	}
	return NULL;
};

// 이름으로 삭제.
void removeContactByName(ContactList* list, const char* name) {
	if (list == NULL || list->head == NULL) return;

	ContactNode* curr = list->head;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0) {
			// 연결 끊기 전에 next 백업
			ContactNode* toDelete = curr;
			ContactNode* nextNode = curr->next;

			// head일 경우
			if (toDelete == list->head) {
				list->head = toDelete->next;
				if (list->head != NULL)
					list->head->prev = NULL;
			}
			// tail일 경우
			else if (toDelete == list->tail) {
				list->tail = toDelete->prev;
				if (list->tail != NULL)
					list->tail->next = NULL;
			}
			// 중간 노드
			else {
				toDelete->prev->next = toDelete->next;
				toDelete->next->prev = toDelete->prev;
			}

			free(toDelete);
			list->size--;
			return;  // 첫 번째 일치 항목만 삭제하고 종료
		}

		curr = curr->next;
	}
}

