#include <iostream>

using namespace std;

// 16�ֽ�
struct A1{
	double a;
	int b;
};
// 24 �� �ṹ��A1������һ������,���Ԫ���� double ��
struct A2{
	A1 aa;
	char b;
};
// 16�ֽ�
struct A3{
	char a;
	int b;
	double c;

	void Print1()			// ��Ա�����п���ֱ��ʹ���Լ��ĳ�Ա����
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