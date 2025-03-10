#include <iostream>
#include "CCallByRef.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    CCallByRef cb;
    int a = 3;
    int b = 5;
    std::cout << cb.AddValue(3, 5) << std::endl;

    int* c = new int(3);
    int* d = new int(4);

    std::cout << cb.pAddRefernce(c, d) << std::endl;;

    return 0;
}