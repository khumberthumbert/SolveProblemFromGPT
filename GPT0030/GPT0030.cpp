#include <iostream>

int main()
{
    int a = 0;
    std::cin >> a;
    if (a % 2 == 0 || a == 0)
    {
        std::cout << "짝수 입니다" << std::endl;
    }
    else {
        std::cout << "홀수 입니다" << std::endl;
    }

    return 0;
}