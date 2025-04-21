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
		cout << "이름: " << this->name << "점수: " << this->score << endl;
	}

	friend bool operator==(const Student& rhs1, const Student& rhs2) {
		return rhs1.name == rhs2.name && rhs1.score == rhs2.score;
	}

	bool operator<(const Student& rhs) {
		return this->score > rhs.score;
		//true가 되면 앞에 둬야겠다고 판단한다.
	}
};



int main(void)
{
	vector<Student> stu;
	stu.emplace_back("김코딩", 70);
	stu.emplace_back("이코딩", 50);
	stu.emplace_back("박코딩", 60);
	stu.emplace_back("나코딩", 30);
	stu.emplace_back("마코딩", 90);
	sort(stu.begin(), stu.end());
	for (const Student& s : stu) {
		s.print();
	}


	return 0;
}