#include <iostream>

class Vector2D
{
private:
    double x, y;

public :
    Vector2D(double x, double y) : x(x), y(y) {}
    ~Vector2D() {

    };

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    //다른 벡터와 더해야 하므로, 매개변수를 참조(&)로 받고, const를 붙여서 변경되지 않도록 함.
    /*
    1. Vector2D를 반환해야만 연산된 결과를 새로운 객체로 반환할 수 있다.

    2. other은 연산의 대상이 되는 벡터이므로 값을 변경하면 안된다 -> const를 붙임으로서 변경되지 않게 보장.

    3. & -> 값 복사가 일어나지 않아 성능 최적화 가능, 복사 없이 원본을 직접 참조 가능.

    4. 함수 끝 const 의미 : 멤버 변수를 변경하지 않겠다는 뜻. 이 함수 안에서 x나 y값을 변경하는 코드가 있으면 컴파일 오류가 발생
    */
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    bool operator==(const Vector2D& other) const {
        return (x == other.x) && (y == other.y);
    }
};

int main()
{
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);
    Vector2D sum = v1 + v2;
    sum.print();

    Vector2D diff = v1 - v2;
    diff.print();

    Vector2D scaled = v1 * 2.0;
    scaled.print();

    bool isEqual = (v1 == v2);
    std::cout << "같은 벡터인가? " << (isEqual ? "Yes" : "No") << std::endl;

    return 0;

}
