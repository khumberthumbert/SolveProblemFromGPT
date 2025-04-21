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
	cout << "��ǰ��: " << this->name << ", ����: " << this->price << "��, ����: " << this->rating << endl;
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
	product.emplace_back("�ٳ���", 3900, 4.3);
	product.emplace_back("����", 8500, 4.5);
	product.emplace_back("����", 18500, 3.7);
	product.emplace_back("����", 5500, 2.7);
	product.emplace_back("�θ���", 10500, 4.9);
	cout << "���� ��" << endl;

	for (const Product& p : product) {
		p.print();
	}

	cout << "���� ��" << endl;

	sort(product.begin(), product.end());

	for (const Product& p : product) {
		p.print();
	}
	

	return 0;
}