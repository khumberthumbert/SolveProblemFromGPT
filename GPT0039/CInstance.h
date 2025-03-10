#ifndef CINSTANCE_H 
//"CINSTANCE_H"라는 매크로가 정의되어 있지 않다면 실행됨
#define CINSTANCE_H 
//"CINSTANCE_H" 매크로를 정의해서, 이후에 이 파일이 다시 포함되더라도 #ifndef CINSTANCE_H에서 막힘

#include <iostream>

class CInstance 
{
public:
	CInstance();
	~CInstance();
};

#endif // #ifndef가 시작된 블록을 끝내는 역할 함.