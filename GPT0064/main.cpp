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
 참조형이라 Rectangle 타입을 모르기 때문에 주로 외부함수는 클래스 내부의 private멤버에 접근할 수 없어서. friend 사용.
*/


int main(void)
{
	Rectangle r1(3, 4);
	Rectangle r2(2, 6);
	Rectangle r3(3, 3);

	cout << "r1의 넓이: " << r1.area() << endl;


	cout << r1 << endl;
	cout << r2 << endl;

	if (r1 == r2)
		cout << "r1과 r2는 같은 넓이입니다." << endl;
	else
		cout << "r1과 r2는 넓이가 다릅니다." << endl;

	cout << "r1의 넓이: " << r1.area() << endl;
	cout << "r2의 넓이: " << r2.area() << endl;
	cout << "r3의 넓이: " << r3.area() << endl;

	return 0;
}