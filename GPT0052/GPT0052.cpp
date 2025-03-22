#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    float score;

public:
    Student() : name(""), age(0), score(0.0) {}
    Student(string name, int age, float score) 
        : name(name), age(age), score(score) {}
    ~Student() {}

    void save(ofstream& outFile) const {
        outFile << name << endl;
        outFile << age << endl;
        outFile << score << endl;
    }

    void load(ifstream& inFile){ 
        getline(inFile, name);
        inFile >> age;
        inFile.ignore();
        inFile >> score;
        inFile.ignore();
    }
    void print() const {
        cout << "이름 : " << name << " 나이 : " << age << " 성적 : " << score << endl;
    };
};

int main()
{
    int countP = 0;
    cout << "몇 명의 정보를 저장하겠습니까? : ";
    cin >> countP;
    cin.ignore();

    vector<Student> students;
    for (int i = 0; i < countP; i++)
    {
        string name;
        int age = 0;
        float score = 0.0;
        cout << "학생의 이름을 입력하세요 : ";
        getline(cin, name);
        cout << "학생의 나이를 입력하세요 : ";
        cin >> age;
        cin.ignore();
        cout << "학생의 성적을 입력하세요 : ";
        cin >> score;
        cin.ignore();

        students.emplace_back(name, age, score);
    }

    ofstream outFile("C:/Users/User/Desktop/Students.txt");

    outFile << students.size() << endl;

    for (const Student& s : students) {
        s.save(outFile);
    }

    outFile.close();

    ifstream inFile("C:/Users/User/Desktop/Students.txt");

    int numStudent = 0;
    inFile >> numStudent;
    inFile.ignore();

    vector<Student> loadedStudent(numStudent);

    for (int i = 0; i < loadedStudent.size(); i++) {
        loadedStudent[i].load(inFile);
    }


    cout << "\n파일에서 읽은 정보 : \n";
    for (int i = 0; i < loadedStudent.size(); i++)
    {
        cout << i + 1 << ". ";
        loadedStudent[i].print();
    }


    return 0;
}