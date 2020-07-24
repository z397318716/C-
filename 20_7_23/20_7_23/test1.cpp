#include <iostream>
using namespace std;
/*
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
*/
template<class T1, class T2>
T1 ADD(T1 num1, T2 num2)
{
	return num1 + num2;
}


int main()
{
	auto n = ADD(1, 3.3);


	return 0;
}