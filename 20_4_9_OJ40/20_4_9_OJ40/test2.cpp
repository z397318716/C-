//递归思想，第n个收件人可以递归到n-1个收件人与n-2个收件人之和
#include<iostream>
using namespace std;

long int Failrec(int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	return (n - 1)*(Failrec(n - 1) + Failrec(n - 2));
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		cout << Failrec(n) << endl;
	}
	return 0;
}