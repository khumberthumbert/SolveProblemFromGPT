#include <iostream>

int main()
{
    std::cout << "배열 크기를 입력하세요. " << std::endl;
    int length;
    std::cin >> length;

    int* array = new int[length];
    for (int i = 0; i < length; i++)
    {
        std::cin >> array[i];
    }
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i] << " ";
    }

    delete[] array;
    return 0;
}