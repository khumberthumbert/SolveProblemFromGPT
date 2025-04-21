#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product
{
public:
	Product(string name = "", int price = 0, float rating = 0.0);
	~Product();

	void const print() const;
	bool operator<(const Product& rhs);
	bool operator==(const Product& rhs);
	

private:
	string name;
	int price;
	float rating;
};

bool Product::operator==(const Product& rhs)
{
	return this->name == rhs.name && this->price == rhs.price;
};

bool Product::operator<(const Product& rhs)
{
	if (this->rating > rhs.rating) return true;
	return false;
};

void const Product::print() const
{
	cout << "상품명: " << this->name << ", 가격: " << this->price << "원, 평점: " << this->rating << endl;
}

Product::Product(string name, int price, float rating) : name(name), price(price), rating(rating)
{
}

Product::~Product()
{
}

int main(void)
{
	vector<Product> product;
	product.emplace_back("바나나", 3900, 4.3);
	product.emplace_back("딸기", 8500, 4.5);
	product.emplace_back("수박", 18500, 3.7);
	product.emplace_back("망고", 5500, 2.7);
	product.emplace_back("두리안", 10500, 4.9);
	cout << "정렬 전" << endl;

	for (const Product& p : product) {
		p.print();
	}

	cout << "정렬 후" << endl;

	sort(product.begin(), product.end());

	for (const Product& p : product) {
		p.print();
	}
	

	return 0;
}