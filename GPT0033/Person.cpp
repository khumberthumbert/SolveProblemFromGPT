#include "Person.h"
#include <iostream>
#include <string>
#include <string.h>


Person::Person() {
	std::cout << "생성자 함수 호출" << std::endl;
};

Person::Person(char name[], int age) {
	std::cout << "사용자 정의 생성자 호출" << std::endl;
	strcpy_s(this->name, name);
	this->age = age;
};

Person::~Person() {
	std::cout << "소멸자 함수 호출" << std::endl;
};

void Person::printInfo() {
	std::cout << "이름 : " << name << ", 나이 : " << age << std::endl;
};