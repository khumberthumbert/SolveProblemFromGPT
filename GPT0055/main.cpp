#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int a = 0;
	int hole = 0, jjak = 0;
	int avg1 = 0, avg2 = 0;
	cout << "���� 10���� �Է��ϼ��� : " << endl;
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	for (auto a : v)
	{
		
		if (a % 2 == 0)
		{
			++jjak;
			avg1 += a;
		}
		else if (a % 2 != 0) {
			++hole;
			avg2 += a;
		}


	}

	cout << "¦�� ���� : " << jjak << ", ��� : " << avg1 / jjak << endl;
	cout << "Ȧ�� ���� : " << hole << ", ��� : " << avg2 / hole << endl;

	return 0;
}