#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student
{
private:
	string name;
	int score;

public:

	Student(string _name, int _score) : name(_name), score(_score) {};
	~Student() {};

	void print() const {
		cout << "�̸�: " << this->name << "����: " << this->score << endl;
	}

	friend bool operator==(const Student& rhs1, const Student& rhs2) {
		return rhs1.name == rhs2.name && rhs1.score == rhs2.score;
	}

	bool operator<(const Student& rhs) {
		return this->score > rhs.score;
		//true�� �Ǹ� �տ� �־߰ڴٰ� �Ǵ��Ѵ�.
	}
};



int main(void)
{
	vector<Student> stu;
	stu.emplace_back("���ڵ�", 70);
	stu.emplace_back("���ڵ�", 50);
	stu.emplace_back("���ڵ�", 60);
	stu.emplace_back("���ڵ�", 30);
	stu.emplace_back("���ڵ�", 90);
	sort(stu.begin(), stu.end());
	for (const Student& s : stu) {
		s.print();
	}


	return 0;
}