#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


class A
{
private:
	static int _scount;
	int _z1;
public:
	A()
	{
		++_scount;
	}
	A(const A&t)
	{
		++_scount;
	}
	static int GetScount()
	{
		//_z1++;	// ��̬��Ա���� ���� ���� �Ǿ�̬��Ա
		return _scount;
	}
};

int A::_scount = 0;		// ��̬��Ա���������������ʼ��,�����е��������


int main()
{

	cout << A::GetScount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetScount() << endl;

	return 0;
}