#include <iostream>
#include <iomanip>

int main()
{
    double a = 0;

    std::cin >> a;
    double result = (a * 1.8) + 32;
    std::cout << "화씨 온도 : " << std::fixed << std::setprecision(1) << result << "F" << std::endl;

    return 0;
}