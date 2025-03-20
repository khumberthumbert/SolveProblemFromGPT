#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string str = "";
	int age = 0;

	cin >> str >> age;

	ofstream outFile("C:/Users/User/data1.txt"); // 파일 열기(쓰기모드)

	if (!outFile) {
		cerr << "파일을 열 수 없습니다!" << endl;
		return 1;
	}

	outFile << str << age << endl;
	outFile.close();

	ifstream inFile("C:/Users/User/data1.txt"); //파일 읽기(읽기 모드)
	if (!inFile) {
		cerr << "파일을 열 수 없습니다" << endl;
		return 1;
	}
	string text;

	while (getline(inFile, text)) {
		cout << str <<" " << age << endl;
	}

	inFile.close();

	return 0;
}
