#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

class MyString
{
public :
	char* str;

public :
	MyString() {
		cout << "MyString()" << endl;
	};
	MyString(const char* strcopy) {
		int len = strlen(strcopy) + 1;
		this->str = new char[len];
		strcpy_s(this->str, len, strcopy);

	};
	~MyString() {
		delete[] str;
		cout << "~MyString()" << endl;
	}

	void print() const {
		cout << this->str << endl;
	};
	
};

int main(void)
{

	MyString s1("Hello");
	MyString s2 = s1;
	s1.print();
	s2.print();
	s1.str[0] = 'X';

	s1.print();
	s2.print();

	return 0;
}