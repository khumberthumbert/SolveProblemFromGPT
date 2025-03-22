#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private :
    string title;
    string author;
    int price;

public:
    Book() : title(""), author(""), price(0) {}
    Book(string title) : title(title), author(""), price(0) {}
    Book(string title, string author) : title(title), author(author), price(0) {}
    Book(string title, string author, int price)
        : title(title), author(author), price(price)
    {}
    ~Book() {}

    void print() const{
        cout << "제목: " << title << " 저자: " << author << " 가격: " << price << endl;
    }

    void print(bool onlyTitle) const{
        if (onlyTitle) {
            cout << " 제목 : " << title << endl;
        }
        else {
            cout << "제목: " << title << " 저자: " << author << " 가격: " << price << endl;
        }
    }
};

int main()
{
    vector<Book> book1;
    book1.emplace_back("C++입문", "김코딩", 25000);
    for (const Book& b : book1) {
        b.print();
    }

    Book* book2 = new Book("C 입문", "김욱환", 13500);
    book2->print();
    book2->print(true);

    vector<Book> book3;
    book3.emplace_back("c언어책", "김욱환");
    for (const Book& b : book3) {
        b.print();
    }

    Book book4("Java책");
    book4.print(true);
  

    delete book2;
    return 0;
}
