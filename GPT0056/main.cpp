#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct Student {

	string name = "";
	int korScore = 0;
	int mathScore = 0;

} Student;

int main(void)
{
	vector<Student> students;
	Student student;
	
	for (int i = 0; i < 2; i++) {
		cout << "학생 " << i + 1 << " 이름:";
		cin >> student.name;
		cout << "국어 점수: ";
		cin >> student.korScore;
		cout << "수학 점수: ";
		cin	>> student.mathScore;
		students.emplace_back(student);
	}

	double avg = 0;
	int korAvg = 0;
	int mathAvg = 0;

	for (auto a : students) {
		avg = (a.korScore + a.mathScore)/2.0f;
		cout << a.name << ": 평균 " << avg << "점" << endl;
		korAvg += a.korScore;
		mathAvg += a.mathScore;
	}

	cout << "국어 평균: " << korAvg/students.size() << "점" << endl;
	cout << "수학 평균: " << mathAvg/students.size() << "점" << endl;

	return 0;
}