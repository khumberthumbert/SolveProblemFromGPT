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
	cout << "¿¬»êÀ» ¼±ÅÃÇÏ¼¼¿ä (0: µ¡¼À, 1: »¬¼À, 2: °ö¼À, 3: ³ª´°¼À) : " << "";
	cin >> a;
	int (*operations[4])(int, int) = { add, subtract, multiply, divide };
	
	cout << "¼ıÀÚ 2°³¸¦ ÀÔ·ÂÇÏ¼¼¿ä: " << "";
	int b, c = 0;
	cin >> b >> c;

	cout << operations[a](b, c);

	return 0;
}