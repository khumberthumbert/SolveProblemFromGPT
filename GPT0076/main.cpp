#include <iostream>
#include <algorithm>

using namespace std;

int add(int a, int b) {	return a + b;}
int subtract(int a, int b) {return a - b;}
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main(void)
{
	int a = 0;
	cout << "������ �����ϼ��� (0: ����, 1: ����, 2: ����, 3: ������) : " << "";
	cin >> a;
	int (*operations[4])(int, int) = { add, subtract, multiply, divide };
	
	cout << "���� 2���� �Է��ϼ���: " << "";
	int b, c = 0;
	cin >> b >> c;

	cout << operations[a](b, c);

	return 0;
}