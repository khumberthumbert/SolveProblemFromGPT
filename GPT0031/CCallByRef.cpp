#include <iostream>
#include "CCallByRef.h"

CCallByRef::CCallByRef() {
	std::cout << "CCallByRef 생성자 함수 호출" << std::endl;
}

CCallByRef::~CCallByRef() {
	std::cout << "CCallByRef 소멸자 함수 호출" << std::endl;
}

int CCallByRef::AddValue(const int a, const int b) {

	return a + b;
}

int CCallByRef::pAddRefernce(int *a, int *b) {
	return *a + *b;
}