#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    int price;

public:
    Book() : title(""), author(""), price(0) {}
    Book(string title) : title(title), author(""), price(0) {}
    Book(string title, string author) : title(title), author(author), price(0) {}
    Book(string title, string author, int price)
        : title(title), author(author), price(price)
    {
    }
    ~Book() {}

    void print() const {
        cout << "제목: " << title << " 저자: " << author << " 가격: " << price << endl;
    }

    void print(bool onlyTitle) const {
        if (onlyTitle) {
            cout << " 제목 : " << title << endl;
        }
        else {
            cout << "제목: " << title << " 저자: " << author << " 가격: " << price << endl;
        }
    }

    string getAuthor() const {
        return this->author;
    }

    string getTitle() const {
        return this->title;
    }
};

class Library : Book{
private:
    string name;
    vector<Book> books;

public:
    Library() : name(""), books() {}
    ~Library() {};
    Library(string name) : name(name), books() {}

    void addBook(const Book& newbook) {

        for (Book& b : books)
        {
            if (b.getTitle() == newbook.getTitle())
            {
                cout << "이미 있는 책 입니다." << endl;
                return;
            }
            
        }
        this->books.emplace_back(newbook);
        
    }

    void printAllBooks() {
        cout << "전체 책 목록:" << endl;
        for (const Book& b : books)
        {
            b.print();
        }
    }
    void printBooksByAuthor(const string& author){

        for (const Book& b : books)
        {
            if (b.getAuthor() == author) {
                cout << b.getAuthor() << "의 책:" << " ";
                b.print();
            }
        }
    }

};

int main()
{
    Library* lib = new Library("중앙 도서관");
    Book book1("C++입문", "김코딩", 25000);
    Book book2("C입문", "박코딩", 20000);
    Book book3("Java입문", "이코딩", 15000);
    lib->addBook(book1);
    lib->addBook(book2);
    lib->addBook(book3);
    lib->addBook(book1);


    lib->printAllBooks();
    lib->printBooksByAuthor("김코딩");
    

    delete lib;
    return 0;
}