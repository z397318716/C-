#include <iostream>

namespace N
{
int a = 20;
int b = 10;

int Add(int left, int right)
{
	return left + right;
}
int Sub(int left, int right)
{
	return left - right;
}

}

using namespace std;
void fun1(int& a, int& b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main1()
{
	/*int ming = 5;
	int &xiaoming = ming;

	cout << &ming << endl;
	cout << &xiaoming << endl;
	cout << xiaoming << endl;*/

	
	/*int a = 5;
	int b = 6;
	fun1(a, b);
	cout << a << b << endl;*/
	
	const int a = 10;
	const int& ra = a;
	double b = 1.23;
	const double& rb = b;	// 在当前环境下该语句不会报错

	system("pause");
	return 0;
}