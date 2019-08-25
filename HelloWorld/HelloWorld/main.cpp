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

int main()
{
	cout << "2\n";
	cout << N::Add(2, 3) << endl;
	cout << "hello!!" << endl;

	system("pause");
	return 0;
}