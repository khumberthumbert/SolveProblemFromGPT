#include <iostream>
#include <fstream>


using namespace std;

class Person {
private:
    string name;
    int age;
    string email;

public:
    Person() {
        cout << "기본 생성자 생성" << endl;
    };
    Person(string name, int age, string email) {
        this->name = name;
        this->age = age;
        this->email = email;
    };
    ~Person() {
        cout << "소멸자 호출" << endl;
    };

    Person save(string name, int age, string email) {
        Person tmp;
        tmp.name = name;
        tmp.age = age;
        tmp.email = email;
        return tmp;
    }
    Person load(string name) {
        
    }
};

int main()
{
    string name;
    int age;
    string email;
    int countP = 0;
    cout << "몇 명의 정보를 저장하겠습니까? (최대 5명)" << " ";
    cin >> countP;
    if (countP > 5 || countP < 0) return 1;
    ofstream outFile("C:/Users/User/Desktop/user1.dat");
    for (int i = 0; i < countP; i++)
    {
        cout << "이름을 입력하세요 : " << " ";
        cin >> name;
        cout << "나이를 입력하세요 : " << " ";
        cin >> age;
        cout << "이메일을 입력하세요 : " << " ";
        cin >> email;
        outFile << name<< " " << age << " " << email << " " << endl;
    }
    outFile.close();

    ifstream inFile("C:/Users/User/Desktop/user1.dat");

    for (int i = 0; i < countP; i++)
    {
        inFile >> name >> age >> email;
        cout << "이름: " << name << " 나이: " << age << " 이메일: " << email << endl;
    }

    return 0;
}