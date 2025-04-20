#include <iostream>
#include <string.h>

using namespace std;

class Student
{
public :
	char* name;
	int age;

	Student(const char* name, const int age) {
		cout << "���� �ؾ���" << endl;
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
		this->age = age;
	}

	Student(const Student& other) {
		cout << "���� ���� ������ ȣ��" << endl;

		int len = strlen(other.name) + 1;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, len, other.name);

		age = other.age;
	}
	
	void print() {
		cout << this->name << this->age << endl;
	}

	~Student() {
		delete[] name;
	}
};

int main(void)
{
	Student* s1 = new Student("���ȯ", 20);
	Student* s2 = new Student(*s1);

	s1->print();
	s2->print();

	s1->name[0] = '��';

	s1->print();
	s2->print();

	delete s1;
	delete s2;

	return 0;
}