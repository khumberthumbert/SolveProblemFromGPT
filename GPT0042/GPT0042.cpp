#include <iostream>
#include <string>
using namespace std;

//그냥 뒤에서부터 반복문 시작하면 되지.
int main()
{
    string str = "";
    cin >> str;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        std::cout << str[i];
    }
    return 0;
}
