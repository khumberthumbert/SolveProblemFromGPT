#include "Person.h"
#include <iostream>
#include <string>
#include <string.h>


Person::Person() {
	std::cout << "������ �Լ� ȣ��" << std::endl;
};

Person::Person(char name[], int age) {
	std::cout << "����� ���� ������ ȣ��" << std::endl;
	strcpy_s(this->name, name);
	this->age = age;
};

Person::~Person() {
	std::cout << "�Ҹ��� �Լ� ȣ��" << std::endl;
};

void Person::printInfo() {
	std::cout << "�̸� : " << name << ", ���� : " << age << std::endl;
};