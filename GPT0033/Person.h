#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person
{
public :
	Person();
	Person(char name[], int age);
	~Person();

	void printInfo();

private:
	char name[30];
	int age;
};

#endif PERSON_H
