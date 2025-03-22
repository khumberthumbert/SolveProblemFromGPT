#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person {
private :
    string name;
    int age;
    string email;

public :
    Person() : name(""), age(0), email("") {}
    Person(string name, int age, string email)
        : name(name), age(age), email(email) {
    }

    void save(ofstream& out) const { 
        out << name << endl;
        out << age << endl;
        out << email << endl;
    }

    void load(ifstream& in) {
        getline(in, name);
        in >> age;
        in.ignore();
        getline(in, email);
    }

    void print() const {
        cout << "이름: " << name << ", 나이: " << age << ", 이메일: " << email << endl;
    }
};


int main()
{
    int countP = 0;
    cout << "몇 명의 정보를 저장하겠습니까? (최대 5명): ";
    cin >> countP;
    cin.ignore();
    if (countP > 5 || countP <= 0) return 1;

    vector<Person> people; // vector는 동적으로 크기를 늘리거나 줄일 수 있음. -> 자동 메모리 관리.
    for (int i = 0; i < countP; ++i)
    {
        string name, email;
        int age;
        cout << "이름을 입력하세요: ";
        getline(cin, name); //왜 getline으로? -> 공백 포함 한 줄 전체를 문자열로 입력받는 함수.
        cout << "나이를 입력하세요: ";
        cin >> age;
        cin.ignore();
        cout << "이메일을 입력하세요: ";
        getline(cin, email);
        people.emplace_back(name, age, email); //emplace_back 기능??
        //.push_back() 또는 .emplace_back()을 사용해 객체를 추가할 수 있다.
        //.push_back() -> 기존에 생성된 객체를 vector에 추가 -> 생성 + 복사. 
        // people.push_back(Person(name, age, email)); 이런식으로 씀.
        //.emplace_back() -> vector안에서 직접 객체를 생성함(생성자 호출);
    }

    ofstream outFile("C:/Users/User/Desktop/user2.dat");
    // people.size() -> vector<Person> people의 요소 개수를 가져옴
    // outFile << 그 값을 파일에 기록함.
    outFile << people.size() << endl;
    
    //const Person& p : 여기서 p는 복사가 아니라 참조(reference)로 받기 때문에 메모리 낭비 없이 처리됨.
    //const를 붙이면 p 내부 데이터를 수정하지 않겠다는 보장.
    //for(Person p : people) -> 매번 복사본 생성(비효율적)
    //for(const Person& p : people) -> 복사 없이 일기만 함.
    for (const Person& p : people) { //여기서 Person객체의 주소를 저장하는 변수 p가 왜 필요? 왜 Person이 아니고 Person&인가?
        p.save(outFile);
    }
    outFile.close();

    ifstream inFile("C:/Users/User/Desktop/user2.dat");
    int numPeople = 0;
    inFile >> numPeople; //사람들 넘버 
    inFile.ignore();

    vector<Person> loadedPeople(numPeople); //vector 생성자가 어떻게 되길래 loadedPeople(숫자) 넣는가? 이 코드의 이유가 뭔가?
    // vector<T>는 숫자를 넣으면 해당 크기만큼 기본 생성된 객체를 미리 생성함.

    for (int i = 0; i < numPeople; ++i)
    {
        loadedPeople[i].load(inFile); // 벡터 객체에는 내가 만든 아무 함수를 쓸 수 있는거야? 아니면 지네릭스로 Person이라는 클래스 안의 함수만 쓸 수 있는거야?
        //지정한 지네릭 클래스의 함수만 사용할 수 있다.
    }
    inFile.close();

    cout << "\n파일에서 읽은 사용자 정보: \n";
    for (int i = 0; i < loadedPeople.size(); ++i) {
        cout << i + 1 << ". ";
        loadedPeople[i].print();
    }
    return 0;
}