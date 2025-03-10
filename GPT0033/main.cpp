#include <iostream>
#include "Person.h"

int main()
{
	std::cout << "이름과 나이를 입력하세요 : " << " ";
	char name[30];
	int age;
	std::cin >> name >> age;

	Person* person = new Person(name, age);
	person->printInfo();

	delete person;
	return 0;
}