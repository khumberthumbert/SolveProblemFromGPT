#include <iostream>

using namespace std;

class Vector2D
{
private:
	double x;
	double y;

public:
	~Vector2D() {
		cout << "소멸자 함수 호출" << endl;
	}

	Vector2D(int x = 0, int y = 0) : x(x), y(y) {};

	//private 멤버 변수에 접근하기 위해서.
	friend Vector2D operator+(const Vector2D& x, const Vector2D& y);

	void print() const
	{
		cout << x << ", " << y << endl;
	}
};

Vector2D operator+(const Vector2D& n1, const Vector2D& n2) {
	Vector2D tmp;
	tmp.x = n1.x + n2.x;
	tmp.y = n1.y + n2.y;
	return tmp;
}

int main()
{
	Vector2D vec1(1, 1);
	vec1.print();

}
