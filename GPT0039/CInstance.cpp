#include <iostream>
#include "CInstance.h"

CInstance::CInstance() {
    std::cout << "생성자 함수 호출" << std::endl;
}

CInstance::~CInstance() {
    std::cout << "소멸자 함수 호출" << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

    //ins는 객체를 직접 저장하는 변수가 아니라... 객체의 메모리 주소를 저장하는 변수다. 항상 명심.
    CInstance *ins = new CInstance();
    
    delete ins;

    return 0;
}