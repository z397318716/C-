#include <iostream>

using namespace std;

class Testtop{
public:
	int m_a;
	int m_b;

	Testtop() :m_a(0), m_b(0)
	{
	}
	Testtop(int a, int b) :m_a(a), m_b(b)
	{

	}
	Testtop operator+(const Testtop &s) const//在函数后加 const 表示 this 不能变  
	{
		Testtop res;
		res.m_a = m_a + s.m_a;
		res.m_b = m_b + s.m_b;

		return res;
	}
};


int main2()
{
	Testtop a(3, 5);
	Testtop b(2, 7);

	Testtop c = a + b;
	cout << c.m_a << ' ' << c.m_b << endl;

	return 0;
}