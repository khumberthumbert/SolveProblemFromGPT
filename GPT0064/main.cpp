#include <iostream>

using namespace std;

class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle(int w_val, int h_val) {
		this->width = w_val;
		this->height = h_val;
	}

	Rectangle(const Rectangle& rhs) {
		width = rhs.width;
		height = rhs.height;
	}

	int area() const {
		return width * height;
	}

	void print() {
		cout << "Rectangle(width=" << this->width << ", height=" << this->height << ")" << endl;
	}

	bool operator==(const Rectangle& other) const {
		
		return width * height == other.width * other.height;
	}

	friend ostream& operator<<(ostream& out, const Rectangle& r) {
		out << "Rectangle(Width=" << r.width << ", height=" << r.height << ")";
		return out;
	}

};

/*
 �������̶� Rectangle Ÿ���� �𸣱� ������ �ַ� �ܺ��Լ��� Ŭ���� ������ private����� ������ �� ���. friend ���.
*/


int main(void)
{
	Rectangle r1(3, 4);
	Rectangle r2(2, 6);
	Rectangle r3(3, 3);

	cout << "r1�� ����: " << r1.area() << endl;


	cout << r1 << endl;
	cout << r2 << endl;

	if (r1 == r2)
		cout << "r1�� r2�� ���� �����Դϴ�." << endl;
	else
		cout << "r1�� r2�� ���̰� �ٸ��ϴ�." << endl;

	cout << "r1�� ����: " << r1.area() << endl;
	cout << "r2�� ����: " << r2.area() << endl;
	cout << "r3�� ����: " << r3.area() << endl;

	return 0;
}