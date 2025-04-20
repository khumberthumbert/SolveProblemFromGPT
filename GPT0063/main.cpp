#include <iostream>

using namespace std;

class Vector2D
{
public :
	int x;
	int y;

	Vector2D() {
		x = 0;
		y = 0;
	}

	Vector2D(int x_val, int y_val) {
		x = x_val;
		y = y_val;
	}

	

	void print() {
		cout << "Vector(" << x << ", " << y << ")" << endl;
	}
};
Vector2D operator+(const Vector2D& other1, const Vector2D& other2) {
	int sumX = other1.x + other2.x;
	int sumY = other1.y + other2.y;
	Vector2D result(sumX, sumY);
	return result;
}

int main(void)
{

	Vector2D v1(3, 4);
	Vector2D v2(1, 2);

	Vector2D v3 = v1 + v2;

	v1.print();
	v2.print();
	v3.print();

	return 0;
}