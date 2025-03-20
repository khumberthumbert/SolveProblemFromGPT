#include <iostream>

using namespace std;

class Person
{
private:
	char* m_name = nullptr;
	int m_age;

public:
	Person();
	Person(const char* name, int age);
	~Person();
};