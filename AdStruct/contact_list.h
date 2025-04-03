#include <stdio.h>
#include "contact.h"

typedef struct ContactList ContactList; // 불투명 포인터로 선언

// 리스트를 동적 생성/해제
ContactList* createContactList(); // 리스트 생성
void destroyContactList(ContactList* list); // 리스트 초기화

// 데이터 추가/삭제
void addContact(ContactList* list,CONTACT contact);	// 새 연락처 추가
void removeContactByName(ContactList* list, const char* name);	// 이름으로 삭제

// 조회
CONTACT* findContactByName(ContactList* list, const char* name); // 이름으로 검색
void printAllContacts(const ContactList* list); // 전체 출력

// 통계
int getTotalHappyMoney(); // 총 축의금 합계
int getTotalSadMoney(); // 총 조의금 합계