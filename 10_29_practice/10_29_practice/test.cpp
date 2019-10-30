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
		//_z1++;	// 静态成员函数 不能 调用 非静态成员
		return _scount;
	}
};

int A::_scount = 0;		// 静态成员变量必须在类外初始化,被所有的类对象共享


int main()
{

	cout << A::GetScount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetScount() << endl;

	return 0;
}