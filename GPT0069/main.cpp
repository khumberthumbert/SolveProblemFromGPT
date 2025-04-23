//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Shape
//{
//public :
//	virtual double area() const = 0;
//	virtual void print() const = 0;
//};
//
//class Circle : Shape
//{
//private:
//	int radius;
//public:
//	Circle(int radius) : radius(radius) {
//		cout << "Circle created" << endl;
//	};
//	~Circle() {
//		cout << "Circle destroyed" << endl;
//	};
//
//	virtual void print() const {
//		cout << "radius: " << radius << endl;
//	};
//
//};
//
//class Rectangle : Shape
//{
//private :
//	int width;
//	int height;
//
//public:
//	Rectangle(int width, int height) : width(width), height(height) {
//		cout << "Rectangle created" << endl;
//	}
//	~Rectangle() {
//		cout << "Rectangle destroyed" << endl;
//	}
//
//	virtual void print() const {
//		cout << "width : " << width << endl;
//		cout << "height : " << height << endl;
//	}
//};
//
//class Rectangle : Shape
//{
//	int width;
//	int height;
//};
//
//int main(void)
//{
//	Shape s = new 
//	vector<Shape*> shapes;
//	shapes.emplace_back("")
//	cout << "정렬 전 모든 도형 출력" << endl;
//	for (const Shape* s : shapes) {
//		s->print();
//	}a
//
//
//	return 0;
//}