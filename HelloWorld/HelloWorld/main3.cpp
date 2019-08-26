#include <iostream>

using namespace std;


struct A{
	int a[100000];
};

A& Test(A& a)
{
	return a;
}

A Test2(A& a)
{
	return a;
}

int main2()
{
	A a;

	/*cout << Test(a) << endl;
	cout << Test2(a) << endl;*/

	for (int i = 0; i < 1000000000; i++)
	{
		Test(a);
	}

	system("pause");
	return 0;
}