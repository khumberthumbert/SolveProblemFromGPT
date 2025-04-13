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
		cout << "�л� " << i + 1 << " �̸�:";
		cin >> student.name;
		cout << "���� ����: ";
		cin >> student.korScore;
		cout << "���� ����: ";
		cin	>> student.mathScore;
		students.emplace_back(student);
	}

	double avg = 0;
	int korAvg = 0;
	int mathAvg = 0;

	for (auto a : students) {
		avg = (a.korScore + a.mathScore)/2.0f;
		cout << a.name << ": ��� " << avg << "��" << endl;
		korAvg += a.korScore;
		mathAvg += a.mathScore;
	}

	cout << "���� ���: " << korAvg/students.size() << "��" << endl;
	cout << "���� ���: " << mathAvg/students.size() << "��" << endl;

	return 0;
}