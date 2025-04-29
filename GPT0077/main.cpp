#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
T myMax(T a, T b) {
	return (a > b) ? a : b;
}

int main(void)
{
	cout << myMax(3, 7) << endl;
	cout << myMax(5.5, 2.3) << endl;
	cout << myMax("apple", "banana") << endl;

	return 0;
}