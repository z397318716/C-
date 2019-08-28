#include <iostream>

using namespace std;

// 16字节
struct A1{
	double a;
	int b;
};
// 24 将 结构体A1看成了一个整体,最大元素是 double 型
struct A2{
	A1 aa;
	char b;
};
// 16字节
struct A3{
	char a;
	int b;
	double c;

	void Print1()			// 成员函数中可以直接使用自己的成员变量
	{
		printf("%d", b);
	}
};


namespace n1
{
	int a;

	void printA()
	{
		printf("%d", a);
	}
}
int main1()
{
	A3 test;
	test.b = 2;
	


	return 0;
}