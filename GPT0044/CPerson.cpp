#include <iostream>
#include "CPerson.h"
#include <cstring>

using namespace std;

Person::Person() {
	cout << "±âº» »ý¼ºÀÚ È£Ãâ" << endl;
}

Person::Person(const char* name, int age) {
	this->m_name = new char[strlen(name) + 1];
	strcpy_s(m_name, strlen(name) + 1, name);
	this->m_age = age;
	cout << "Person »ý¼ºµÊ : " << m_name << "," << age << endl;
}

Person::~Person() {
	cout << "¼Ò¸êÀÚ È£Ãâ µÊ: [" << m_name << "]" << endl;
	delete[] m_name;
}