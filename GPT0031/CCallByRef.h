#ifndef CCALLBYREF_H
#define CCALLBYREF_H
class CCallByRef
{
public:
	CCallByRef();
	~CCallByRef();

	int AddValue(const int a, const int b);
	int pAddRefernce(int *a, int *b);
};
#endif
