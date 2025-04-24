#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Shape
{
public :
	virtual double area() const = 0;
	virtual void print() const = 0;
	virtual ~Shape() {}

};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double radius) : radius(radius) {
		cout << "Circle created" << endl;
	};
	~Circle() {
		cout << "Circle destroyed" << endl;
	};

	virtual double area() const {
		return (this->radius * this->radius) * 3.14;
	};

	virtual void print() const {
		cout << "radius: " << radius << endl;
	};

	

};

class Rectangle : public Shape
{
private :
	double width;
	double height;

public:
	Rectangle(double width, double height) : width(width), height(height) {
		cout << "Rectangle created" << endl;
	}
	~Rectangle() {
		cout << "Rectangle destroyed" << endl;
	}

	virtual double area() const {
		return width * height;
	}

	virtual void print() const {
		cout << "width : " << width << endl;
		cout << "height : " << height << endl;
	}
};

int main(void)
{
	Shape* c1 = new Circle(1.0);
	Shape* r1 = new Rectangle(4.0, 7.0);


	vector<Shape*> shapes;
	shapes.emplace_back(c1);
	shapes.emplace_back(r1);

	cout << "정렬 전 모든 도형 출력" << endl;

	for (const Shape* s : shapes) {
		s->print();
	}

	sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
		return a->area() > b->area();  // 넓이 내림차순 정렬
	});

	for (const Shape* s : shapes) {
		s->print();
	}
	for (const Shape* s : shapes) {
		delete s;
	}


	return 0;
}